import math

#Valores aptos para el programa:
# i1=125   i2=216   d=10

def Biseccion (i1, i2, d):
 xl=(d/10)
 xu=(d/10)*9
 imax=15
 es=0.05
 iter=0
 xr=0
 xrold=xr
 xr=((xl+xu)/2)
 iter+=1

 if (xr!=0):
  ea=(abs(float (xr-xrold)/xr))*100
  
 bandera=0
 while(ea>es and iter<=imax):
  if bandera==1:
   rold=xr
   xr=((xl+xu)/2)
   iter+=1
   if (xr!=0):
    ea=(abs(float (xr-xrold)/xr))*100
  
  fdexl=-(2*i1)/pow(xl,3) + (2*i2)/pow((d-xl),3)
  fdexr=-(2*i1)/pow(xr,3) + (2*i2)/pow((d-xr),3)
  test=fdexl*fdexr
             
  if (test<0):
   xu=xr
  elif (test>0):
   xl=xr
  else:
   ea=0
  bandera=1
 print'Número de iteraciones: ',iter
 return xr
 #Fin Funcion Biseccion
 
def NewtonRaphson (x0,i1,i2,imax,d):
 xr=x0
 iter=0
 es=0.05
 ea=1
 
 while (ea>es and iter<=imax):
   xrold=xr
   fdex=-(2*i1)/pow(xr,3) + (2*i2)/pow((d-xr),3)
   fpdex=6*i1/pow(xr,4)+(6*i2)/pow((d-xr),4)
   xr=xr-fdex/fpdex
   iter+=1
   if xr!=0:
     ea=abs((xr-xrold)/xr)*100
 print'Número de iteraciones: ',iter
 return xr
 #Fin Funcion Newton-Raphson
 
def Secante (i1,i2,imax,d):
 es=0.01
 #Grafica prueba de escritorio - parte 1/2
 print'PRUEBA DE ESCRITORIO    //es=',es
 print'===================='
 print'iter|\txrold |    xr    |  fdexrold |  fdexr    |  ea  |'
 print'---------------------------------------------------------'

 #valores iniciales
 xant=3
 x0=4
 xrold=xant
 xr=x0
 iter=0
 ea=1
 while (ea>es and iter<=imax):
 #Calcular datos de la tabla
  if iter>0:
   #Hago una copia del xr.
   aux=xr
   #Calculo el nuevo xr. Aproximacion a la raiz
   xr=xr-(fdexr*(xrold-xr))/(fdexrold-fdexr)
   #Asigno a xrold, el anteultimo valor que tuvo xr
   xrold=aux
  fdexrold=-(2*i1)/pow(xrold,3) + (2*i2)/pow((d-xrold),3)
  fdexr=-(2*i1)/pow(xr,3) + (2*i2)/pow((d-xr),3)
  if (xr!=0):
   ea=abs(float(xr-xrold)/xr)*100
  #Grafico Prueba de Escritorio - parte 2/2
  print round(iter,2),'  |  ',round(xrold,3),'  |  ',round(xr,3),'  |  ',round(fdexrold,3),'  |  ',round(fdexr,3),'  |  ',round(ea,5),'|'
  #Aumento iterador. Numero de iteraciones = Numero de xr calculados
  iter+=1
 print 'El número de iteraciones es: ',iter-1
 #devuelvo valor a la funcion principal
 return xr

def GraficadeFpdeX (d, raiz):
 raizxr='Xr=',round(raiz,5)
 create_text(700,900,'d(E(r))/dx',tam=10,ancla='CENTER',color='blue')
 create_text(700,160,raizxr,tam=10,ancla='CENTER')
 xl=(d/10)
 xu=(d/10)*9
 create_line(100,150,100,900,color='black')
 create_line(50,200,900,200,color='black')
 i=xl
 while i<=xu:
  fdex=-(2*i1)/pow(i,3) + (2*i2)/pow((d-i),3)
  fdex2=-(2*i1)/pow((i+0.5),3) + (2*i2)/pow((d-(i+0.5)),3)
  create_circle(i*100,fdex+200,5,color='black')
  create_line(i*100,fdex+200,(i+0.5)*100,fdex2+200,color='blue')
  i=i+0.5
  #print 'i es: ',i,'y fdex: ',fdex
 return
 #Fin Funcion GraficadeFpdeX
 
def GraficadeFppdeX (d):
 create_text(350,850,'d2(E(r))/dx2',tam=10,ancla='CENTER',color='red')
 xl=(d/10)
 xu=(d/10)*9
 i=xl
 while i<=xu:
  fdex=(6*i1)/pow(i,4) + (6*i2)/pow((d-i),4)
  fdex2=(6*i1)/pow((i+0.5),4) + (6*i2)/pow((d-(i+0.5)),4)
  create_circle(i*100,fdex+200,5,color='black')
  create_line(i*100,fdex+200,(i+0.5)*100,fdex2+200,color='red')
  i=i+0.5
 return
 #Fin Funcion GraficadeFppdeX
 
def GraficadeFdeX (d):
 create_text(220,500,'E(r)',tam=10,ancla='CENTER',color='green')
 xl=(d/10)
 xu=(d/10)*9
 i=xl
 fdexl=i1/pow(xl,2) + i2/pow((d-xl),2)
 create_filled_circle(xl*100,fdexl+200,30,'black','yellow')
 E1='I1=',i1
 E2='I2=',i2
 create_text(xl*100+180,fdexl+200,E1,tam=6,ancla='CENTER',color='black')
 while i<xu:
  fdex=i1/pow(i,2) + i2/pow((d-i),2)
  fdex2=i1/pow((i+0.5),2) + i2/pow((d-(i+0.5)),2)
  create_circle(i*100,fdex+200,5,color='black')
  create_line(i*100,fdex+200,(i+0.5)*100,fdex2+200,color='green')
  i=i+0.5
 create_filled_circle(i*100,fdex2+200,30,'black','yellow')
 create_text(i*100-180,fdex2+200,E2,tam=6,ancla='CENTER',color='black')
 return
 #Fin Funcion GraficadeFppdeX

#Programa Principal
print 'Programa para calcular el punto de mínima luminancia entre dos fuentes de luz'
print '============================'
i1=float(raw_input('Ingrese I1: '))
i2=float(raw_input('Ingrese I2: '))
d=float(raw_input('Ingrese Distancia: '))
print 'Que método desea utilizar?:'
print ' Opción 1: M. de la Bisección'
print ' Opción 2: M. de Newton-Rapshon'
print ' Opción 3: M. de la Secante'
eleccion=int(raw_input('Deseo utilizar la opción: '))

if eleccion==1:
 raiz = Biseccion (i1, i2, d)
 print 'El punto buscado es: ',round(raiz,3)
 GraficadeFpdeX (d, raiz)
 GraficadeFdeX (d)
elif eleccion==2:
 x0=float(raw_input('Ingrese x0: '))
 imax=15
 raiz = NewtonRaphson (x0, i1, i2, imax,d)
 print 'El punto buscado es: ',round(raiz,3)
 GraficadeFpdeX (d, raiz)
 GraficadeFppdeX(d)
 GraficadeFdeX (d)
elif eleccion==3:
 imax=15
 raiz = Secante (i1, i2, imax,d)
 print 'El punto buscado es: ',round(raiz,3)
 GraficadeFpdeX (d, raiz)
 GraficadeFdeX (d)
else:
  print'Te equivocaste, che'