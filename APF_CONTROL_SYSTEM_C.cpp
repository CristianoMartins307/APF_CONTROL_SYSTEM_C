
#include <Stdlib.h>
#include <String.h>
#include <math.h>
#include <Psim.h>

// PLACE GLOBAL VARIABLES OR USER FUNCTIONS HERE...

//CONSTANTES (EQUACAO RECORRENCIA) DO FILTRO NOTCH
#define beta0_notch 9.996859405152093e-01
#define beta1_notch  -1.999357673314048
#define beta2_notch 9.996859405152093e-01
#define alfa0_notch 1
#define alfa1_notch -1.999357673314048
#define alfa2_notch 9.993718810304186e-01

//VARIAVEIS DE SINAIS DO FILTRO NOTCH
//SHUNT A
float u_notch_shunt_A = 0;
float u_1_notch_shunt_A = 0;
float u_2_notch_shunt_A = 0;
float y_notch_shunt_A = 0;
float y_1_notch_shunt_A= 0;
float y_2_notch_shunt_A = 0;
float y_notch_shunt_A_n1 = 0;
//SHUNT B
float u_notch_shunt_B = 0;
float u_1_notch_shunt_B = 0;
float u_2_notch_shunt_B = 0;
float y_notch_shunt_B = 0;
float y_1_notch_shunt_B = 0;
float y_2_notch_shunt_B = 0;
float y_notch_shunt_B_n1 = 0;
//SHUNT C
float u_notch_shunt_C = 0;
float u_1_notch_shunt_C = 0;
float u_2_notch_shunt_C = 0;
float y_notch_shunt_C = 0;
float y_1_notch_shunt_C = 0;
float y_2_notch_shunt_C = 0;
float y_notch_shunt_C_n1 = 0;
// SERIE A
float u_notch_serie_A = 0;
float u_1_notch_serie_A = 0;
float u_2_notch_serie_A = 0;
float y_notch_serie_A = 0;
float y_1_notch_serie_A = 0;
float y_2_notch_serie_A = 0;
float y_notch_serie_A_n1 = 0;
// SERIE B
float u_notch_serie_B = 0;
float u_1_notch_serie_B = 0;
float u_2_notch_serie_B = 0;
float y_notch_serie_B = 0;
float y_1_notch_serie_B = 0;
float y_2_notch_serie_B = 0;
float y_notch_serie_B_n1 = 0;
// SERIE C
float u_notch_serie_C = 0;
float u_1_notch_serie_C = 0;
float u_2_notch_serie_C = 0;
float y_notch_serie_C = 0;
float y_1_notch_serie_C = 0;
float y_2_notch_serie_C = 0;
float y_notch_serie_C_n1 = 0;




//CONSTANTES DOS CONTROLADORES
//SHUNT
// 60Hz
#define B0_1_PARALELO 0.00006597 
#define B1_1_PARALELO 0.00000000 
#define B2_1_PARALELO -0.00006597 
#define A0_1_PARALELO 1.00000000 
#define A1_1_PARALELO -1.99998202 
#define A2_1_PARALELO 0.99999623 
//180
#define B0_3_PARALELO 0.00019791 
#define B1_3_PARALELO 0.00000000 
#define B2_3_PARALELO -0.00019791 
#define A0_3_PARALELO 1.00000000 
#define A1_3_PARALELO -1.99986079 
#define A2_3_PARALELO 0.99998869 
// 300Hz
#define B0_5_PARALELO 0.00032983 
#define B1_5_PARALELO 0.00000000 
#define B2_5_PARALELO -0.00032983 
#define A0_5_PARALELO 1.00000000 
#define A1_5_PARALELO -1.99962588 
#define A2_5_PARALELO 0.99998115 
// 420Hz
#define B0_7_PARALELO 0.00046173 
#define B1_7_PARALELO 0.00000000 
#define B2_7_PARALELO -0.00046173 
#define A0_7_PARALELO 1.00000000 
#define A1_7_PARALELO -1.99927735 
#define A2_7_PARALELO 0.99997362 
//540Hz
#define B0_9_PARALELO 0.00059358 
#define B1_9_PARALELO 0.00000000 
#define B2_9_PARALELO -0.00059358 
#define A0_9_PARALELO 1.00000000 
#define A1_9_PARALELO -1.99881524 
#define A2_9_PARALELO 0.99996608 
//660
#define B0_11_PARALELO 0.00072538 
#define B1_11_PARALELO 0.00000000 
#define B2_11_PARALELO -0.00072538 
#define A0_11_PARALELO 1.00000000 
#define A1_11_PARALELO -1.99823964 
#define A2_11_PARALELO 0.99995855 
//780Hz
#define B0_13_PARALELO 0.00085712 
#define B1_13_PARALELO 0.00000000 
#define B2_13_PARALELO -0.00085712 
#define A0_13_PARALELO 1.00000000 
#define A1_13_PARALELO -1.99755065 
#define A2_13_PARALELO 0.99995102 
//900Hz
#define B0_15_PARALELO 0.00098878 
#define B1_15_PARALELO 0.00000000 
#define B2_15_PARALELO -0.00098878 
#define A0_15_PARALELO 1.00000000 
#define A1_15_PARALELO -1.99674839 
#define A2_15_PARALELO 0.99994350 

//SERIE 
// 60Hz
#define B0_1_SERIE 0.00022619 
#define B1_1_SERIE 0.00000000 
#define B2_1_SERIE -0.00022619 
#define A0_1_SERIE 1.00000000 
#define A1_1_SERIE -1.99998353 
#define A2_1_SERIE 0.99999774 

// 180Hz
#define B0_3_SERIE 0.00067856 
#define B1_3_SERIE 0.00000000 
#define B2_3_SERIE -0.00067856 
#define A0_3_SERIE 1.00000000 
#define A1_3_SERIE -1.99986531 
#define A2_3_SERIE 0.99999321 

// 300Hz
#define B0_5_SERIE 0.00113087 
#define B1_5_SERIE 0.00000000 
#define B2_5_SERIE -0.00113087 
#define A0_5_SERIE 1.00000000 
#define A1_5_SERIE -1.99963342 
#define A2_5_SERIE 0.99998869 

// 420Hz
#define B0_7_SERIE 0.00158307 
#define B1_7_SERIE 0.00000000 
#define B2_7_SERIE -0.00158307 
#define A0_7_SERIE 1.00000000 
#define A1_7_SERIE -1.99928790 
#define A2_7_SERIE 0.99998417

//540Hz
#define B0_9_SERIE 0.00203515 
#define B1_9_SERIE 0.00000000 
#define B2_9_SERIE -0.00203515 
#define A0_9_SERIE 1.00000000 
#define A1_9_SERIE -1.99882880 
#define A2_9_SERIE 0.99997965  

//660
#define B0_11_SERIE 0.00248704 
#define B1_11_SERIE 0.00000000 
#define B2_11_SERIE -0.00248704 
#define A0_11_SERIE 1.00000000 
#define A1_11_SERIE -1.99825621 
#define A2_11_SERIE 0.99997513 

//780Hz
#define B0_13_SERIE 0.00293872 
#define B1_13_SERIE 0.00000000 
#define B2_13_SERIE -0.00293872 
#define A0_13_SERIE 1.00000000 
#define A1_13_SERIE -1.99757022 
#define A2_13_SERIE 0.99997061 


//900Hz
#define B0_15_SERIE 0.00339015 
#define B1_15_SERIE 0.00000000 
#define B2_15_SERIE -0.00339015 
#define A0_15_SERIE 1.00000000 
#define A1_15_SERIE -1.99677096 
#define A2_15_SERIE 0.99996610 


//GANHO PROPORCIONAL 
#define KP_PARALELO 155
#define KP_SERIE 5
#define K_DAMPING 3



//VARIAVEIS DOS CONTROLADORES
//SHUNT A
float e_shunt_A=0; 
float e_shunt_A_n1=0; 
float e_shunt_A_n2=0;

float u1_shunt_A=0; 
float u1_shunt_A_n1=0; 
float u1_shunt_A_n2=0;

float u3_shunt_A=0; 
float u3_shunt_A_n1=0; 
float u3_shunt_A_n2=0;

float u5_shunt_A=0; 
float u5_shunt_A_n1=0; 
float u5_shunt_A_n2=0;

float u7_shunt_A=0; 
float u7_shunt_A_n1=0; 
float u7_shunt_A_n2=0;

float u9_shunt_A=0; 
float u9_shunt_A_n1=0; 
float u9_shunt_A_n2=0;

float u11_shunt_A=0; 
float u11_shunt_A_n1=0; 
float u11_shunt_A_n2=0;

float u13_shunt_A=0; 
float u13_shunt_A_n1=0; 
float u13_shunt_A_n2=0;

float u15_shunt_A=0; 
float u15_shunt_A_n1=0; 
float u15_shunt_A_n2=0;


float up_shunt_A=0;

float utotal_shunt_A=0;
float utotal_shunt_A_n1=0;

float i_load_shunt_A = 0;
float i_filter_shunt_A = 0;

// SHUNT B
float e_shunt_B = 0; 
float e_shunt_B_n1 = 0; 
float e_shunt_B_n2 = 0;

float u1_shunt_B = 0; 
float u1_shunt_B_n1 = 0; 
float u1_shunt_B_n2 = 0;

float u3_shunt_B = 0; 
float u3_shunt_B_n1 = 0; 
float u3_shunt_B_n2 = 0;

float u5_shunt_B = 0; 
float u5_shunt_B_n1 = 0; 
float u5_shunt_B_n2 = 0;

float u7_shunt_B = 0; 
float u7_shunt_B_n1 = 0; 
float u7_shunt_B_n2 = 0;

float u9_shunt_B = 0; 
float u9_shunt_B_n1 = 0; 
float u9_shunt_B_n2 = 0;

float u11_shunt_B = 0; 
float u11_shunt_B_n1 = 0; 
float u11_shunt_B_n2 = 0;

float u13_shunt_B = 0; 
float u13_shunt_B_n1 = 0; 
float u13_shunt_B_n2 = 0;

float u15_shunt_B = 0; 
float u15_shunt_B_n1 = 0; 
float u15_shunt_B_n2 = 0;

float up_shunt_B = 0;

float utotal_shunt_B = 0;
float utotal_shunt_B_n1 = 0;

float i_load_shunt_B = 0;
float i_filter_shunt_B = 0;
// SHUNT C
float e_shunt_C = 0; 
float e_shunt_C_n1 = 0; 
float e_shunt_C_n2 = 0;

float u1_shunt_C = 0; 
float u1_shunt_C_n1 = 0; 
float u1_shunt_C_n2 = 0;

float u3_shunt_C = 0; 
float u3_shunt_C_n1 = 0; 
float u3_shunt_C_n2 = 0;

float u5_shunt_C = 0; 
float u5_shunt_C_n1 = 0; 
float u5_shunt_C_n2 = 0;

float u7_shunt_C = 0; 
float u7_shunt_C_n1 = 0; 
float u7_shunt_C_n2 = 0;

float u9_shunt_C = 0; 
float u9_shunt_C_n1 = 0; 
float u9_shunt_C_n2 = 0;

float u11_shunt_C = 0; 
float u11_shunt_C_n1 = 0; 
float u11_shunt_C_n2 = 0;

float u13_shunt_C = 0; 
float u13_shunt_C_n1 = 0; 
float u13_shunt_C_n2 = 0;

float u15_shunt_C = 0; 
float u15_shunt_C_n1 = 0; 
float u15_shunt_C_n2 = 0;

float up_shunt_C = 0;

float utotal_shunt_C = 0;
float utotal_shunt_C_n1 = 0;

float i_load_shunt_C = 0;
float i_filter_shunt_C = 0;

// SERIE A
float e_serie_A = 0; 
float e_serie_A_n1 = 0; 
float e_serie_A_n2 = 0;

float u1_serie_A = 0; 
float u1_serie_A_n1 = 0; 
float u1_serie_A_n2 = 0;

float u3_serie_A = 0; 
float u3_serie_A_n1 = 0; 
float u3_serie_A_n2 = 0;

float u5_serie_A = 0; 
float u5_serie_A_n1 = 0; 
float u5_serie_A_n2 = 0;

float u7_serie_A = 0; 
float u7_serie_A_n1 = 0; 
float u7_serie_A_n2 = 0;

float u9_serie_A = 0; 
float u9_serie_A_n1 = 0; 
float u9_serie_A_n2 = 0;

float u11_serie_A = 0; 
float u11_serie_A_n1 = 0; 
float u11_serie_A_n2 = 0;

float u13_serie_A = 0; 
float u13_serie_A_n1 = 0; 
float u13_serie_A_n2 = 0;

float u15_serie_A = 0; 
float u15_serie_A_n1 = 0; 
float u15_serie_A_n2 = 0;

float up_serie_A = 0;

float utotal_serie_A = 0;
float utotal_serie_A_n1 = 0;

float v_load_serie_A = 0;
float v_filter_serie_A = 0;
float in_damping_A  = 0;

// SERIE B
float e_serie_B = 0; 
float e_serie_B_n1 = 0; 
float e_serie_B_n2 = 0;

float u1_serie_B = 0; 
float u1_serie_B_n1 = 0; 
float u1_serie_B_n2 = 0;

float u3_serie_B = 0; 
float u3_serie_B_n1 = 0; 
float u3_serie_B_n2 = 0;

float u5_serie_B = 0; 
float u5_serie_B_n1 = 0; 
float u5_serie_B_n2 = 0;

float u7_serie_B = 0; 
float u7_serie_B_n1 = 0; 
float u7_serie_B_n2 = 0;

float u9_serie_B = 0; 
float u9_serie_B_n1 = 0; 
float u9_serie_B_n2 = 0;

float u11_serie_B = 0; 
float u11_serie_B_n1 = 0; 
float u11_serie_B_n2 = 0;

float u13_serie_B = 0; 
float u13_serie_B_n1 = 0; 
float u13_serie_B_n2 = 0;

float u15_serie_B = 0; 
float u15_serie_B_n1 = 0; 
float u15_serie_B_n2 = 0;

float up_serie_B = 0;

float utotal_serie_B = 0;
float utotal_serie_B_n1 = 0;

float v_load_serie_B = 0;
float v_filter_serie_B = 0;
float in_damping_B = 0;

// SERIE C
float e_serie_C = 0; 
float e_serie_C_n1 = 0; 
float e_serie_C_n2 = 0;

float u1_serie_C = 0; 
float u1_serie_C_n1 = 0; 
float u1_serie_C_n2 = 0;

float u3_serie_C = 0; 
float u3_serie_C_n1 = 0; 
float u3_serie_C_n2 = 0;

float u5_serie_C = 0; 
float u5_serie_C_n1 = 0; 
float u5_serie_C_n2 = 0;

float u7_serie_C = 0; 
float u7_serie_C_n1 = 0; 
float u7_serie_C_n2 = 0;

float u9_serie_C = 0; 
float u9_serie_C_n1 = 0; 
float u9_serie_C_n2 = 0;

float u11_serie_C = 0; 
float u11_serie_C_n1 = 0; 
float u11_serie_C_n2 = 0;

float u13_serie_C = 0; 
float u13_serie_C_n1 = 0; 
float u13_serie_C_n2 = 0;

float u15_serie_C = 0; 
float u15_serie_C_n1 = 0; 
float u15_serie_C_n2 = 0;

float up_serie_C = 0;

float utotal_serie_C = 0;
float utotal_serie_C_n1 = 0;

float v_load_serie_C = 0;
float v_filter_serie_C = 0;
float in_damping_C = 0;




/////////////////////////////////////////////////////////////////////
// FUNCTION: SimulationStep
//   This function runs at every time step.
//double t: (read only) time
//double delt: (read only) time step as in Simulation control
//double *in: (read only) zero based array of input values. in[0] is the first node, in[1] second input...
//double *out: (write only) zero based array of output values. out[0] is the first node, out[1] second output...
//int *pnError: (write only)  assign  *pnError = 1;  if there is an error and set the error message in szErrorMsg
//    strcpy(szErrorMsg, "Error message here..."); 
// DO NOT CHANGE THE NAME OR PARAMETERS OF THIS FUNCTION
void SimulationStep(
		double t, double delt, double *in, double *out,
		 int *pnError, char * szErrorMsg,
		 void ** reserved_UserData, int reserved_ThreadIndex, void * reserved_AppPtr)
{
// ENTER YOUR CODE HERE...

//ENTRADAS DO SISTEMA
//SHUNT A
u_notch_shunt_A = in[0]; 
i_filter_shunt_A = in[1];
//SHUNT B
u_notch_shunt_B = in[2]; 
i_filter_shunt_B = in[3];
// SHUNT C
u_notch_shunt_C = in[4]; 
i_filter_shunt_C = in[5];
// SERIE A
u_notch_serie_A = in[6]; 
v_load_serie_A = in[7];
in_damping_A =in[8];
// SERIE B
u_notch_serie_B = in[9]; 
v_load_serie_B = in[10];
in_damping_B = in[11];
// SERIE C
u_notch_serie_C = in[12]; 
v_load_serie_C = in[13];
in_damping_C = in[14];



//EQUACOES RECORRENCIA FILTRO NOTCH
//SHUNT A
y_notch_shunt_A = beta0_notch*u_notch_shunt_A + beta1_notch*u_1_notch_shunt_A + beta2_notch*u_2_notch_shunt_A - alfa1_notch*y_1_notch_shunt_A - alfa2_notch*y_2_notch_shunt_A;
//SHUNT B
y_notch_shunt_B = beta0_notch * u_notch_shunt_B + beta1_notch * u_1_notch_shunt_B + beta2_notch * u_2_notch_shunt_B - alfa1_notch * y_1_notch_shunt_B - alfa2_notch * y_2_notch_shunt_B;
// SHUNT C
y_notch_shunt_C = beta0_notch * u_notch_shunt_C + beta1_notch * u_1_notch_shunt_C + beta2_notch * u_2_notch_shunt_C - alfa1_notch * y_1_notch_shunt_C - alfa2_notch * y_2_notch_shunt_C;
// SERIE A
y_notch_serie_A = beta0_notch*u_notch_serie_A + beta1_notch*u_1_notch_serie_A + beta2_notch*u_2_notch_serie_A - alfa1_notch*y_1_notch_serie_A - alfa2_notch*y_2_notch_serie_A;
// SERIE B
y_notch_serie_B = beta0_notch*u_notch_serie_B + beta1_notch*u_1_notch_serie_B + beta2_notch*u_2_notch_serie_B - alfa1_notch*y_1_notch_serie_B - alfa2_notch*y_2_notch_serie_B;
// SERIE C
y_notch_serie_C = beta0_notch*u_notch_serie_C + beta1_notch*u_1_notch_serie_C + beta2_notch*u_2_notch_serie_C - alfa1_notch*y_1_notch_serie_C - alfa2_notch*y_2_notch_serie_C;


//SAIDA DE REF
//SHUNT A
out[1] = y_notch_shunt_A;
//SHUNT B
out[3] = y_notch_shunt_B;
// SHUNT C
out[5] = y_notch_shunt_C;
//SERIE A
out[7] = y_notch_serie_A;
//SERIE B
out[9] = y_notch_serie_B;
// SERIE C
out[11] = y_notch_serie_C;


//CALCULO DO ERRO
//SHUNT A
e_shunt_A  = y_notch_shunt_A  - i_filter_shunt_A ;
//SHUNT B
e_shunt_B = y_notch_shunt_B - i_filter_shunt_B;
// SHUNT C
e_shunt_C = y_notch_shunt_C - i_filter_shunt_C;
// SERIE A
e_serie_A = y_notch_serie_A - v_load_serie_A - (K_DAMPING * in_damping_A) ;
// SERIE B
e_serie_B = y_notch_serie_B - v_load_serie_B - (K_DAMPING * in_damping_B);
// SERIE C
e_serie_C = y_notch_serie_C - v_load_serie_C - (K_DAMPING * in_damping_C);


//ATUALIZACAO VARIAVEIS FILTRO NOTCH
//SHUNT A
u_2_notch_shunt_A = u_1_notch_shunt_A;
y_2_notch_shunt_A = y_1_notch_shunt_A;
u_1_notch_shunt_A = u_notch_shunt_A;
y_1_notch_shunt_A  = y_notch_shunt_A;
y_notch_shunt_A_n1=y_notch_shunt_A;
// SHUNT B
u_2_notch_shunt_B = u_1_notch_shunt_B;
y_2_notch_shunt_B = y_1_notch_shunt_B;
u_1_notch_shunt_B = u_notch_shunt_B;
y_1_notch_shunt_B = y_notch_shunt_B;
y_notch_shunt_B_n1 = y_notch_shunt_B;
// SHUNT C
u_2_notch_shunt_C = u_1_notch_shunt_C;
y_2_notch_shunt_C = y_1_notch_shunt_C;
u_1_notch_shunt_C = u_notch_shunt_C;
y_1_notch_shunt_C = y_notch_shunt_C;
y_notch_shunt_C_n1 = y_notch_shunt_C;
// SERIE A
u_2_notch_serie_A = u_1_notch_serie_A;
y_2_notch_serie_A = y_1_notch_serie_A;
u_1_notch_serie_A = u_notch_serie_A;
y_1_notch_serie_A  = y_notch_serie_A;
y_notch_serie_A_n1 = y_notch_serie_A;
// SERIE B
u_2_notch_serie_B = u_1_notch_serie_B;
y_2_notch_serie_B = y_1_notch_serie_B;
u_1_notch_serie_B = u_notch_serie_B;
y_1_notch_serie_B  = y_notch_serie_B;
y_notch_serie_B_n1 = y_notch_serie_B;
// SERIE C
u_2_notch_serie_C = u_1_notch_serie_C;
y_2_notch_serie_C = y_1_notch_serie_C;
u_1_notch_serie_C = u_notch_serie_C;
y_1_notch_serie_C  = y_notch_serie_C;
y_notch_serie_C_n1 = y_notch_serie_C;




//CONTROLE 
//SHUNT A
//60Hz
u1_shunt_A = e_shunt_A*B0_1_PARALELO + e_shunt_A_n1*B1_1_PARALELO + e_shunt_A_n2*B2_1_PARALELO - u1_shunt_A_n1*A1_1_PARALELO  - u1_shunt_A_n2*A2_1_PARALELO;
//60Hz
u3_shunt_A = e_shunt_A*B0_3_PARALELO + e_shunt_A_n1*B1_3_PARALELO + e_shunt_A_n2*B2_3_PARALELO - u3_shunt_A_n1*A1_3_PARALELO  - u3_shunt_A_n2*A2_3_PARALELO;
//300Hz
u5_shunt_A = e_shunt_A*B0_5_PARALELO + e_shunt_A_n1*B1_5_PARALELO + e_shunt_A_n2*B2_5_PARALELO - u5_shunt_A_n1*A1_5_PARALELO  - u5_shunt_A_n2*A2_5_PARALELO;
//420Hz
u7_shunt_A = e_shunt_A*B0_7_PARALELO + e_shunt_A_n1*B1_7_PARALELO + e_shunt_A_n2*B2_7_PARALELO - u7_shunt_A_n1*A1_7_PARALELO  - u7_shunt_A_n2*A2_7_PARALELO;
//540Hz
u9_shunt_A = e_shunt_A*B0_9_PARALELO + e_shunt_A_n1*B1_9_PARALELO + e_shunt_A_n2*B2_9_PARALELO - u9_shunt_A_n1*A1_9_PARALELO  - u9_shunt_A_n2*A2_9_PARALELO;
//660Hz
u11_shunt_A = e_shunt_A*B0_11_PARALELO + e_shunt_A_n1*B1_11_PARALELO + e_shunt_A_n2*B2_11_PARALELO - u11_shunt_A_n1*A1_11_PARALELO  - u11_shunt_A_n2*A2_11_PARALELO;
//780Hz
u13_shunt_A = e_shunt_A*B0_13_PARALELO + e_shunt_A_n1*B1_13_PARALELO + e_shunt_A_n2*B2_13_PARALELO - u13_shunt_A_n1*A1_13_PARALELO  - u13_shunt_A_n2*A2_13_PARALELO;
//780Hz
u15_shunt_A = e_shunt_A*B0_15_PARALELO + e_shunt_A_n1*B1_15_PARALELO + e_shunt_A_n2*B2_15_PARALELO - u15_shunt_A_n1*A1_15_PARALELO  - u15_shunt_A_n2*A2_15_PARALELO;

up_shunt_A=KP_PARALELO*e_shunt_A; //não muda

utotal_shunt_A  = u1_shunt_A  + u3_shunt_A  + u5_shunt_A  + u7_shunt_A  + u9_shunt_A  + u11_shunt_A  + u13_shunt_A  +u15_shunt_A  + up_shunt_A ;
// SHUNT B
// 60Hz
u1_shunt_B = e_shunt_B * B0_1_PARALELO + e_shunt_B_n1 * B1_1_PARALELO + e_shunt_B_n2 * B2_1_PARALELO - u1_shunt_B_n1 * A1_1_PARALELO - u1_shunt_B_n2 * A2_1_PARALELO;
// 60Hz
u3_shunt_B = e_shunt_B * B0_3_PARALELO + e_shunt_B_n1 * B1_3_PARALELO + e_shunt_B_n2 * B2_3_PARALELO - u3_shunt_B_n1 * A1_3_PARALELO - u3_shunt_B_n2 * A2_3_PARALELO;
// 300Hz
u5_shunt_B = e_shunt_B * B0_5_PARALELO + e_shunt_B_n1 * B1_5_PARALELO + e_shunt_B_n2 * B2_5_PARALELO - u5_shunt_B_n1 * A1_5_PARALELO - u5_shunt_B_n2 * A2_5_PARALELO;
// 420Hz
u7_shunt_B = e_shunt_B * B0_7_PARALELO + e_shunt_B_n1 * B1_7_PARALELO + e_shunt_B_n2 * B2_7_PARALELO - u7_shunt_B_n1 * A1_7_PARALELO - u7_shunt_B_n2 * A2_7_PARALELO;
// 540Hz
u9_shunt_B = e_shunt_B * B0_9_PARALELO + e_shunt_B_n1 * B1_9_PARALELO + e_shunt_B_n2 * B2_9_PARALELO - u9_shunt_B_n1 * A1_9_PARALELO - u9_shunt_B_n2 * A2_9_PARALELO;
// 660Hz
u11_shunt_B = e_shunt_B * B0_11_PARALELO + e_shunt_B_n1 * B1_11_PARALELO + e_shunt_B_n2 * B2_11_PARALELO - u11_shunt_B_n1 * A1_11_PARALELO - u11_shunt_B_n2 * A2_11_PARALELO;
// 780Hz
u13_shunt_B = e_shunt_B * B0_13_PARALELO + e_shunt_B_n1 * B1_13_PARALELO + e_shunt_B_n2 * B2_13_PARALELO - u13_shunt_B_n1 * A1_13_PARALELO - u13_shunt_B_n2 * A2_13_PARALELO;
// 780Hz
u15_shunt_B = e_shunt_B * B0_15_PARALELO + e_shunt_B_n1 * B1_15_PARALELO + e_shunt_B_n2 * B2_15_PARALELO - u15_shunt_B_n1 * A1_15_PARALELO - u15_shunt_B_n2 * A2_15_PARALELO;

up_shunt_B = KP_PARALELO * e_shunt_B; // não muda

utotal_shunt_B = u1_shunt_B + u3_shunt_B + u5_shunt_B + u7_shunt_B + u9_shunt_B + u11_shunt_B + u13_shunt_B + u15_shunt_B + up_shunt_B;
// SHUNT C
// 60Hz
u1_shunt_C = e_shunt_C * B0_1_PARALELO + e_shunt_C_n1 * B1_1_PARALELO + e_shunt_C_n2 * B2_1_PARALELO - u1_shunt_C_n1 * A1_1_PARALELO - u1_shunt_C_n2 * A2_1_PARALELO;
// 60Hz
u3_shunt_C = e_shunt_C * B0_3_PARALELO + e_shunt_C_n1 * B1_3_PARALELO + e_shunt_C_n2 * B2_3_PARALELO - u3_shunt_C_n1 * A1_3_PARALELO - u3_shunt_C_n2 * A2_3_PARALELO;
// 300Hz
u5_shunt_C = e_shunt_C * B0_5_PARALELO + e_shunt_C_n1 * B1_5_PARALELO + e_shunt_C_n2 * B2_5_PARALELO - u5_shunt_C_n1 * A1_5_PARALELO - u5_shunt_C_n2 * A2_5_PARALELO;
// 420Hz
u7_shunt_C = e_shunt_C * B0_7_PARALELO + e_shunt_C_n1 * B1_7_PARALELO + e_shunt_C_n2 * B2_7_PARALELO - u7_shunt_C_n1 * A1_7_PARALELO - u7_shunt_C_n2 * A2_7_PARALELO;
// 540Hz
u9_shunt_C = e_shunt_C * B0_9_PARALELO + e_shunt_C_n1 * B1_9_PARALELO + e_shunt_C_n2 * B2_9_PARALELO - u9_shunt_C_n1 * A1_9_PARALELO - u9_shunt_C_n2 * A2_9_PARALELO;
// 660Hz
u11_shunt_C = e_shunt_C * B0_11_PARALELO + e_shunt_C_n1 * B1_11_PARALELO + e_shunt_C_n2 * B2_11_PARALELO - u11_shunt_C_n1 * A1_11_PARALELO - u11_shunt_C_n2 * A2_11_PARALELO;
// 780Hz
u13_shunt_C = e_shunt_C * B0_13_PARALELO + e_shunt_C_n1 * B1_13_PARALELO + e_shunt_C_n2 * B2_13_PARALELO - u13_shunt_C_n1 * A1_13_PARALELO - u13_shunt_C_n2 * A2_13_PARALELO;
// 780Hz
u15_shunt_C = e_shunt_C * B0_15_PARALELO + e_shunt_C_n1 * B1_15_PARALELO + e_shunt_C_n2 * B2_15_PARALELO - u15_shunt_C_n1 * A1_15_PARALELO - u15_shunt_C_n2 * A2_15_PARALELO;

up_shunt_C = KP_PARALELO * e_shunt_C; // não muda

utotal_shunt_C = u1_shunt_C + u3_shunt_C + u5_shunt_C + u7_shunt_C + u9_shunt_C + u11_shunt_C + u13_shunt_C + u15_shunt_C + up_shunt_C;
// SERIE A
// 60Hz
u1_serie_A = e_serie_A * B0_1_SERIE + e_serie_A_n1 * B1_1_SERIE + e_serie_A_n2 * B2_1_SERIE - u1_serie_A_n1 * A1_1_SERIE - u1_serie_A_n2 * A2_1_SERIE;
// 60Hz
u3_serie_A = e_serie_A * B0_3_SERIE + e_serie_A_n1 * B1_3_SERIE + e_serie_A_n2 * B2_3_SERIE - u3_serie_A_n1 * A1_3_SERIE - u3_serie_A_n2 * A2_3_SERIE;
// 300Hz
u5_serie_A = e_serie_A * B0_5_SERIE + e_serie_A_n1 * B1_5_SERIE + e_serie_A_n2 * B2_5_SERIE - u5_serie_A_n1 * A1_5_SERIE - u5_serie_A_n2 * A2_5_SERIE;
// 420Hz
u7_serie_A = e_serie_A * B0_7_SERIE + e_serie_A_n1 * B1_7_SERIE + e_serie_A_n2 * B2_7_SERIE - u7_serie_A_n1 * A1_7_SERIE - u7_serie_A_n2 * A2_7_SERIE;
// 540Hz
u9_serie_A = e_serie_A * B0_9_SERIE + e_serie_A_n1 * B1_9_SERIE + e_serie_A_n2 * B2_9_SERIE - u9_serie_A_n1 * A1_9_SERIE - u9_serie_A_n2 * A2_9_SERIE;
// 660Hz
u11_serie_A = e_serie_A * B0_11_SERIE + e_serie_A_n1 * B1_11_SERIE + e_serie_A_n2 * B2_11_SERIE - u11_serie_A_n1 * A1_11_SERIE - u11_serie_A_n2 * A2_11_SERIE;
// 780Hz
u13_serie_A = e_serie_A * B0_13_SERIE + e_serie_A_n1 * B1_13_SERIE + e_serie_A_n2 * B2_13_SERIE - u13_serie_A_n1 * A1_13_SERIE - u13_serie_A_n2 * A2_13_SERIE;
// 780Hz
u15_serie_A = e_serie_A * B0_15_SERIE + e_serie_A_n1 * B1_15_SERIE + e_serie_A_n2 * B2_15_SERIE - u15_serie_A_n1 * A1_15_SERIE - u15_serie_A_n2 * A2_15_SERIE;

up_serie_A = KP_SERIE * e_serie_A; // não muda

utotal_serie_A = u1_serie_A + u3_serie_A + u5_serie_A + u7_serie_A + u9_serie_A + u11_serie_A + u13_serie_A + u15_serie_A + up_serie_A;

// SERIE B
// 60Hz
u1_serie_B = e_serie_B * B0_1_SERIE + e_serie_B_n1 * B1_1_SERIE + e_serie_B_n2 * B2_1_SERIE - u1_serie_B_n1 * A1_1_SERIE - u1_serie_B_n2 * A2_1_SERIE;
// 60Hz
u3_serie_B = e_serie_B * B0_3_SERIE + e_serie_B_n1 * B1_3_SERIE + e_serie_B_n2 * B2_3_SERIE - u3_serie_B_n1 * A1_3_SERIE - u3_serie_B_n2 * A2_3_SERIE;
// 300Hz
u5_serie_B = e_serie_B * B0_5_SERIE + e_serie_B_n1 * B1_5_SERIE + e_serie_B_n2 * B2_5_SERIE - u5_serie_B_n1 * A1_5_SERIE - u5_serie_B_n2 * A2_5_SERIE;
// 420Hz
u7_serie_B = e_serie_B * B0_7_SERIE + e_serie_B_n1 * B1_7_SERIE + e_serie_B_n2 * B2_7_SERIE - u7_serie_B_n1 * A1_7_SERIE - u7_serie_B_n2 * A2_7_SERIE;
// 540Hz
u9_serie_B = e_serie_B * B0_9_SERIE + e_serie_B_n1 * B1_9_SERIE + e_serie_B_n2 * B2_9_SERIE - u9_serie_B_n1 * A1_9_SERIE - u9_serie_B_n2 * A2_9_SERIE;
// 660Hz
u11_serie_B = e_serie_B * B0_11_SERIE + e_serie_B_n1 * B1_11_SERIE + e_serie_B_n2 * B2_11_SERIE - u11_serie_B_n1 * A1_11_SERIE - u11_serie_B_n2 * A2_11_SERIE;
// 780Hz
u13_serie_B = e_serie_B * B0_13_SERIE + e_serie_B_n1 * B1_13_SERIE + e_serie_B_n2 * B2_13_SERIE - u13_serie_B_n1 * A1_13_SERIE - u13_serie_B_n2 * A2_13_SERIE;
// 780Hz
u15_serie_B = e_serie_B * B0_15_SERIE + e_serie_B_n1 * B1_15_SERIE + e_serie_B_n2 * B2_15_SERIE - u15_serie_B_n1 * A1_15_SERIE - u15_serie_B_n2 * A2_15_SERIE;

up_serie_B = KP_SERIE * e_serie_B; // não muda

utotal_serie_B = u1_serie_B + u3_serie_B + u5_serie_B + u7_serie_B + u9_serie_B + u11_serie_B + u13_serie_B + u15_serie_B + up_serie_B;

// SERIE C
// 60Hz
u1_serie_C = e_serie_C * B0_1_SERIE + e_serie_C_n1 * B1_1_SERIE + e_serie_C_n2 * B2_1_SERIE - u1_serie_C_n1 * A1_1_SERIE - u1_serie_C_n2 * A2_1_SERIE;
// 60Hz
u3_serie_C = e_serie_C * B0_3_SERIE + e_serie_C_n1 * B1_3_SERIE + e_serie_C_n2 * B2_3_SERIE - u3_serie_C_n1 * A1_3_SERIE - u3_serie_C_n2 * A2_3_SERIE;
// 300Hz
u5_serie_C = e_serie_C * B0_5_SERIE + e_serie_C_n1 * B1_5_SERIE + e_serie_C_n2 * B2_5_SERIE - u5_serie_C_n1 * A1_5_SERIE - u5_serie_C_n2 * A2_5_SERIE;
// 420Hz
u7_serie_C = e_serie_C * B0_7_SERIE + e_serie_C_n1 * B1_7_SERIE + e_serie_C_n2 * B2_7_SERIE - u7_serie_C_n1 * A1_7_SERIE - u7_serie_C_n2 * A2_7_SERIE;
// 540Hz
u9_serie_C = e_serie_C * B0_9_SERIE + e_serie_C_n1 * B1_9_SERIE + e_serie_C_n2 * B2_9_SERIE - u9_serie_C_n1 * A1_9_SERIE - u9_serie_C_n2 * A2_9_SERIE;
// 660Hz
u11_serie_C = e_serie_C * B0_11_SERIE + e_serie_C_n1 * B1_11_SERIE + e_serie_C_n2 * B2_11_SERIE - u11_serie_C_n1 * A1_11_SERIE - u11_serie_C_n2 * A2_11_SERIE;
// 780Hz
u13_serie_C = e_serie_C * B0_13_SERIE + e_serie_C_n1 * B1_13_SERIE + e_serie_C_n2 * B2_13_SERIE - u13_serie_C_n1 * A1_13_SERIE - u13_serie_C_n2 * A2_13_SERIE;
// 780Hz
u15_serie_C = e_serie_C * B0_15_SERIE + e_serie_C_n1 * B1_15_SERIE + e_serie_C_n2 * B2_15_SERIE - u15_serie_C_n1 * A1_15_SERIE - u15_serie_C_n2 * A2_15_SERIE;

up_serie_C = KP_SERIE * e_serie_C; // não muda

utotal_serie_C = u1_serie_C + u3_serie_C + u5_serie_C + u7_serie_C + u9_serie_C + u11_serie_C + u13_serie_C + u15_serie_C + up_serie_C;


//SAIDA DO SISTEMA
//SHUNT A
out[0]=utotal_shunt_A_n1;
// SHUNT B
out[2] = utotal_shunt_B_n1;
// SHUNT C
out[4] = utotal_shunt_C_n1;
// SERIE A
out[6] = utotal_serie_A_n1;
// SERIE B
out[8] = utotal_serie_B_n1;
// SERIE C
out[10] = utotal_serie_C_n1;


//ATUALIZACAO VARIAVEIS DE CONTROLE
//SHUNT A
e_shunt_A_n2= e_shunt_A_n1; 
e_shunt_A_n1= e_shunt_A ; 

u1_shunt_A_n2=u1_shunt_A_n1;
u1_shunt_A_n1=u1_shunt_A ;

u3_shunt_A_n2=u3_shunt_A_n1;
u3_shunt_A_n1=u3_shunt_A ;

u5_shunt_A_n2=u5_shunt_A_n1;
u5_shunt_A_n1=u5_shunt_A;

u7_shunt_A_n2=u7_shunt_A_n1;
u7_shunt_A_n1=u7_shunt_A ;


u9_shunt_A_n2=u9_shunt_A_n1;
u9_shunt_A_n1=u9_shunt_A ;

u11_shunt_A_n2=u11_shunt_A_n1;
u11_shunt_A_n1=u11_shunt_A ;

u13_shunt_A_n2=u13_shunt_A_n1;
u13_shunt_A_n1=u13_shunt_A ;

u15_shunt_A_n2=u15_shunt_A_n1;
u15_shunt_A_n1=u15_shunt_A ;
utotal_shunt_A_n1=utotal_shunt_A ;


// SHUNT B
e_shunt_B_n2 = e_shunt_B_n1; 
e_shunt_B_n1 = e_shunt_B; 

u1_shunt_B_n2 = u1_shunt_B_n1;
u1_shunt_B_n1 = u1_shunt_B;

u3_shunt_B_n2 = u3_shunt_B_n1;
u3_shunt_B_n1 = u3_shunt_B;

u5_shunt_B_n2 = u5_shunt_B_n1;
u5_shunt_B_n1 = u5_shunt_B;

u7_shunt_B_n2 = u7_shunt_B_n1;
u7_shunt_B_n1 = u7_shunt_B;

u9_shunt_B_n2 = u9_shunt_B_n1;
u9_shunt_B_n1 = u9_shunt_B;

u11_shunt_B_n2 = u11_shunt_B_n1;
u11_shunt_B_n1 = u11_shunt_B;

u13_shunt_B_n2 = u13_shunt_B_n1;
u13_shunt_B_n1 = u13_shunt_B;

u15_shunt_B_n2 = u15_shunt_B_n1;
u15_shunt_B_n1 = u15_shunt_B;

utotal_shunt_B_n1 = utotal_shunt_B;

// SHUNT C
e_shunt_C_n2 = e_shunt_C_n1; 
e_shunt_C_n1 = e_shunt_C; 

u1_shunt_C_n2 = u1_shunt_C_n1;
u1_shunt_C_n1 = u1_shunt_C;

u3_shunt_C_n2 = u3_shunt_C_n1;
u3_shunt_C_n1 = u3_shunt_C;

u5_shunt_C_n2 = u5_shunt_C_n1;
u5_shunt_C_n1 = u5_shunt_C;

u7_shunt_C_n2 = u7_shunt_C_n1;
u7_shunt_C_n1 = u7_shunt_C;

u9_shunt_C_n2 = u9_shunt_C_n1;
u9_shunt_C_n1 = u9_shunt_C;

u11_shunt_C_n2 = u11_shunt_C_n1;
u11_shunt_C_n1 = u11_shunt_C;

u13_shunt_C_n2 = u13_shunt_C_n1;
u13_shunt_C_n1 = u13_shunt_C;

u15_shunt_C_n2 = u15_shunt_C_n1;
u15_shunt_C_n1 = u15_shunt_C;

utotal_shunt_C_n1 = utotal_shunt_C;
// SERIE A
e_serie_A_n2 = e_serie_A_n1;
e_serie_A_n1 = e_serie_A;

u1_serie_A_n2 = u1_serie_A_n1;
u1_serie_A_n1 = u1_serie_A;

u3_serie_A_n2 = u3_serie_A_n1;
u3_serie_A_n1 = u3_serie_A;

u5_serie_A_n2 = u5_serie_A_n1;
u5_serie_A_n1 = u5_serie_A;

u7_serie_A_n2 = u7_serie_A_n1;
u7_serie_A_n1 = u7_serie_A;

u9_serie_A_n2 = u9_serie_A_n1;
u9_serie_A_n1 = u9_serie_A;

u11_serie_A_n2 = u11_serie_A_n1;
u11_serie_A_n1 = u11_serie_A;

u13_serie_A_n2 = u13_serie_A_n1;
u13_serie_A_n1 = u13_serie_A;

u15_serie_A_n2 = u15_serie_A_n1;
u15_serie_A_n1 = u15_serie_A;

utotal_serie_A_n1 = utotal_serie_A;

// SERIE B
e_serie_B_n2 = e_serie_B_n1;
e_serie_B_n1 = e_serie_B;

u1_serie_B_n2 = u1_serie_B_n1;
u1_serie_B_n1 = u1_serie_B;

u3_serie_B_n2 = u3_serie_B_n1;
u3_serie_B_n1 = u3_serie_B;

u5_serie_B_n2 = u5_serie_B_n1;
u5_serie_B_n1 = u5_serie_B;

u7_serie_B_n2 = u7_serie_B_n1;
u7_serie_B_n1 = u7_serie_B;

u9_serie_B_n2 = u9_serie_B_n1;
u9_serie_B_n1 = u9_serie_B;

u11_serie_B_n2 = u11_serie_B_n1;
u11_serie_B_n1 = u11_serie_B;

u13_serie_B_n2 = u13_serie_B_n1;
u13_serie_B_n1 = u13_serie_B;

u15_serie_B_n2 = u15_serie_B_n1;
u15_serie_B_n1 = u15_serie_B;

utotal_serie_B_n1 = utotal_serie_B;

// SERIE C
e_serie_C_n2 = e_serie_C_n1;
e_serie_C_n1 = e_serie_C;

u1_serie_C_n2 = u1_serie_C_n1;
u1_serie_C_n1 = u1_serie_C;

u3_serie_C_n2 = u3_serie_C_n1;
u3_serie_C_n1 = u3_serie_C;

u5_serie_C_n2 = u5_serie_C_n1;
u5_serie_C_n1 = u5_serie_C;

u7_serie_C_n2 = u7_serie_C_n1;
u7_serie_C_n1 = u7_serie_C;

u9_serie_C_n2 = u9_serie_C_n1;
u9_serie_C_n1 = u9_serie_C;

u11_serie_C_n2 = u11_serie_C_n1;
u11_serie_C_n1 = u11_serie_C;

u13_serie_C_n2 = u13_serie_C_n1;
u13_serie_C_n1 = u13_serie_C;

u15_serie_C_n2 = u15_serie_C_n1;
u15_serie_C_n1 = u15_serie_C;

utotal_serie_C_n1 = utotal_serie_C;

}


/////////////////////////////////////////////////////////////////////
// FUNCTION: SimulationBegin
//   Initialization function. This function runs once at the beginning of simulation
//   For parameter sweep or AC sweep simulation, this function runs at the beginning of each simulation cycle.
//   Use this function to initialize static or global variables.
//const char *szId: (read only) Name of the C-block 
//int nInputCount: (read only) Number of input nodes
//int nOutputCount: (read only) Number of output nodes
//int nParameterCount: (read only) Number of parameters is always zero for C-Blocks.  Ignore nParameterCount and pszParameters
//int *pnError: (write only)  assign  *pnError = 1;  if there is an error and set the error message in szErrorMsg
//    strcpy(szErrorMsg, "Error message here..."); 
// DO NOT CHANGE THE NAME OR PARAMETERS OF THIS FUNCTION
void SimulationBegin(
		const char *szId, int nInputCount, int nOutputCount,
		 int nParameterCount, const char ** pszParameters,
		 int *pnError, char * szErrorMsg,
		 void ** reserved_UserData, int reserved_ThreadIndex, void * reserved_AppPtr)
{
// ENTER INITIALIZATION CODE HERE...




}


/////////////////////////////////////////////////////////////////////
// FUNCTION: SimulationEnd
//   Termination function. This function runs once at the end of simulation
//   For parameter sweep or AC sweep simulation, this function runs at the end of each simulation cycle.
//   Use this function to de-allocate any allocated memory or to save the result of simulation in an alternate file.
// Ignore all parameters for C-block 
// DO NOT CHANGE THE NAME OR PARAMETERS OF THIS FUNCTION
void SimulationEnd(const char *szId, void ** reserved_UserData, int reserved_ThreadIndex, void * reserved_AppPtr)
{




}


