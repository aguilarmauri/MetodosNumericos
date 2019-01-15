#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>
using namespace std;

float Biseccion (float, float, float, float, float);
float NewtonRaphson (float, float, float, int, float);
float Secante (float,float,int,float);
void graficas (float);


int main()
{
    int eleccion, imax;
    float i1, i2, d, xl, xu, x0, raiz;
    
    cout<<"Software para el calculo del punto minimo de iluminancia: "<<endl;    
    cout<<"========================================================"<<endl<<endl;    
    cout<<"Ingrese I1: ";
    cin>>i1;
    cout<<"Ahora I2: ";
    cin>>i2;
    cout<<"Distancia de separacion en metros de las fuentes: ";
    cin>>d;
    cout<<endl<<"Que metodo desea utilizar?:"<<endl;
    cout<<" Opcion 1: M. de la Biseccion"<<endl;
    cout<<" Opcion 2: M. de Newton-Rapshon"<<endl;
    cout<<" Opcion 3: M. de la Secante"<<endl;
    cout<<"Deseo utilizar la opcion: ";
    cin>>eleccion;
    cout<<endl;
    
    if (eleccion==1)
    {
     xl=d/10;
     xu=(d/10)*9;
     raiz = Biseccion (xl,xu,i1,i2,d);
    }
    else if (eleccion==2)
     {
      cout<<"Ingrese x0 (ej. "<<(d/2)<<"): ";
      cin>>x0;
      imax=15;
      raiz = NewtonRaphson (x0, i1, i2, imax,d);
     }
    else if (eleccion==3)
    {
         imax=15;
         raiz = Secante (i1,i2,imax,d);
    }
    else
      cout<<"Te equivocaste, che";
 
    cout<<"\n----------------------------------";
    cout<<"\nEl punto buscado es: "<<raiz;   
    cout<<"\n----------------------------------"<<endl<<endl;
    graficas(raiz);

    system("PAUSE");
    return 0;
}//FIN PROGRAMA PRINCIPAL

float Biseccion (float xl, float xu, float i1, float i2, float d)
{
      int iter, imax=15, n=12;
      float xr=0, ea, es=0.05, test, xrold, fdexl, fdexr;
      iter=0;
      
      //Graficar prueba de escritorio - parte 1
      cout<<"PRUEBA DE ESCRITORIO"<<endl;
      cout<<"====================="<<endl;
      cout<<"iter|\txl     |   xr      |\txu     |   f(xl)    |   f(xr)  |  ea|"<<endl;

      //Biseccion
      do{
             xrold=xr;
             xr=((xl+xu)/2);
             iter+=1;
             
             if (xr!=0)
              ea=(abs(float (xr-xrold)/xr))*100;
             fdexl=-(2*i1)/pow(xl,3) + (2*i2)/pow((d-xl),3);
             fdexr=-(2*i1)/pow(xr,3) + (2*i2)/pow((d-xr),3);
             test=fdexl*fdexr;
             
             if (test<0)
              xu=xr;
             else if (test>0)
              xl=xr;
             else
              ea=0;
             
             //Grafica prueba de escritorio - parte 2
             cout<<"----------------------------------------------------------------------"<<endl;
             cout<<setiosflags(ios::fixed)<<setprecision(4)<<iter<<"  |  "<<xl<<"  |  "<<xr<<"  |  "<<xu<<"  |  "<<fdexl<<"  |  "<<fdexr<<"  |  "<<ea<<endl;
      }
      while(ea>es or iter<=imax);
      cout<<"\n----------------------------------";
      cout<<"\nNumero de iteraciones: "<<iter;
      cout<<"\n----------------------------------"<<endl;
      return xr;
}

float NewtonRaphson (float x0,float i1,float i2,int imax,float d)
{
 float es,ea,xrold,fdex,fpdex,xr;
 int iter;

 xr=x0;
 iter=0;
 es=0.05;
 ea=1;
 
 //Graficar prueba de escritorio - parte 1
 cout<<"\nPRUEBA DE ESCRITORIO"<<endl;
 cout<<"====================="<<endl;
 cout<<"iter|\txi     |   fdex      |\tfpdex     |   ea    |"<<endl;
      
 while (ea>es and iter<=imax){
   xrold=xr;
   fdex=-(2*i1)/pow(xr,3) + (2*i2)/pow((d-xr),3);
   fpdex=6*i1/pow(xr,4)+(6*i2)/pow((d-xr),4);
   xr=xr-fdex/fpdex;
   iter+=1;
   if (xr!=0)
     ea=abs((xr-xrold)/xr)*100;
   //Grafica prueba de escritorio - parte 2
   cout<<"----------------------------------------------------------------------"<<endl;
   cout<<setiosflags(ios::fixed)<<setprecision(4)<<iter<<"  |  "<<xr<<"  |  "<<fdex<<"  |  "<<fpdex<<"  |  "<<ea<<"  |  "<<endl;
 }
 cout<<"\n----------------------------------";
 cout<<"\nNumero de iteraciones: "<<iter;
 cout<<"\n----------------------------------"<<endl;
 return xr;
}

float Secante (float i1,float i2,int imax,float d)
{
 float es,ea,xrold,aux,fdexr,fdexrold,xr,xant,x0;
 int iter;
 
 es=0.01;//para 4 cifras significativas es=0.01    para 2 cs es=0.05

 //Grafica prueba de escritorio - parte 1/2
 cout<<"\nPRUEBA DE ESCRITORIO"<<" //es="<<es<<endl;
 cout<<"====================="<<endl;
 cout<<"iter|  xrold  |    xr    |  fdexrold |  fdexr    |   ea \t|"<<endl;
 cout<<"------------------------------------------------------------------"<<endl;

 //valores iniciales
 xant=3;
 x0=4;
 xrold=xant;
 xr=x0;
 iter=0;
 do{
                //Calcular datos de la tabla
                if (iter>0)
                {
                           aux=xr;
                           //Aproximacion a la raiz
                           xr=xr-(fdexr*(xrold-xr))/(fdexrold-fdexr);
                           xrold=aux;
                }
                fdexrold=-(2*i1)/pow(xrold,3) + (2*i2)/pow((d-xrold),3);
                fdexr=-(2*i1)/pow(xr,3) + (2*i2)/pow((d-xr),3);
                if (xr!=0)
                  ea=abs((xr-xrold)/xr)*100;
                
                //Grafica prueba de escritorio - parte 2/2
                cout<<setiosflags(ios::fixed)<<setprecision(4)<<iter<<"   | "<<xrold<<"  |  "<<xr<<"  |  "<<fdexrold<<"  |  "<<fdexr<<"  |  "<<ea<<"\t|"<<endl; 
                iter+=1;
 }
 while (ea>es && iter<=imax);
 //fin del ciclo
                 
 cout<<"\n----------------------------------";
 cout<<"\nNumero de iteraciones: "<<iter-1;
 cout<<"\n----------------------------------"<<endl;
 return xr;
}//fin de la funcion



void graficas (float raiz)
{
     cout<<"GRAFICA DE E(r)"<<endl;
     cout<<"=============================="<<endl;
     cout<<" E(r)||             |    "<<endl;
     cout<<"     | \\            |    "<<endl;
     cout<<"     |  \\           |    "<<endl;
     cout<<"     |   \\_________/     "<<endl;
     cout<<"    _|_________________r  "<<endl;
     cout<<"     |       xr="<<raiz<<endl;
     
          cout<<"\n\nGRAFICA DE LA DERIVADA DE E(r)"<<endl;
     cout<<"=============================="<<endl;
     cout<<"E'(r)|              |    "<<endl;
     cout<<"     |              |    "<<endl;
     cout<<"     |              |    "<<endl;
     cout<<"     |         ____/     "<<endl;
     cout<<"    _|________/_______r  "<<endl;
     cout<<"     |    ___/xr="<<raiz<<endl;
     cout<<"         /              "<<endl;
     cout<<"        /               "<<endl;
     


      return;
}
