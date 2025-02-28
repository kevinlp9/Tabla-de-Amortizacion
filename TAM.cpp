#include<iostream>
#include <math.h>
#include<conio.h>
using namespace std;
void amtz(double *rentas, double *intereses, double *amortizacion, double *saldo, double prestamo, int anios, double interes, double renta, int i) 
{
    if (i <= anios) {
        intereses[i] = prestamo * interes;
        amortizacion[i] = renta - intereses[i];
        saldo[i] = prestamo - amortizacion[i];
        rentas[i] = renta;
        prestamo = saldo[i];
        i+=1;
        amtz(rentas,intereses,amortizacion,saldo, prestamo, anios, interes, renta,i);
    }
}
void totales(double *rentas, double *intereses, double *amortizacion, double *total, int anios, int i)
{
    if (i <= anios) {
        total[0] += rentas[i];
        total[1] += intereses[i];
        total[2] += amortizacion[i];
        totales(rentas,intereses,amortizacion,total,anios, i + 1);
    }
}

int main(){
	double prestamo,interes,renta;
	int anios,anio;
	double *rentas,*intereses,*amortizacion,*saldo,*total;
	cout<<"TABLA DE AMORTIZACION (METODO FRANCES)\n";
	cout<<"Calcule el monto total de su prestamo\n";
	cout<<"\nIngrese monto: ";cin>>prestamo;
	cout<<"\nIngrese la tasa de interes: ";cin>>interes;
	cout<<"\nIngrese el plazo (anios): ";cin>>anios;
    interes /= 100;
    renta = (prestamo * interes) / (1 - pow(1 + interes, -anios));
    anio=anios+1;
    rentas=new double[anio];
    intereses=new double[anio];
    amortizacion=new double[anio];
    saldo=new double[anio];
    total=new double[3];
    int i=1;
    amtz(rentas,intereses,amortizacion,saldo, prestamo, anios, interes, renta, i);
    totales(rentas,intereses,amortizacion,total, anios, i);
    saldo[0]=prestamo;
    
    system("cls");
    
    cout<<"PERIODO\t\tRENTA\t    INTERES\t   AMORTIZACION\t    SALDO\n";
    for (int i = 0; i < anios + 1; i++) {
        printf("\n %d\t|%10.2f\t|%10.2f\t|%10.2f\t|%10.2f\n", i, rentas[i],intereses[i],amortizacion[i], (saldo[i]));
        cout<<"___________________________________________________________________\n";
    }
    cout<<"\nTOTAL";
    for (int i = 0; i < 3; i++) {
        printf("\t|%10.2lf",total[i]);
    }
    cout<<"\n";
	return 0;
}

