#include <math.h>
#include <iostream>
#include "conio.h"

using namespace std;

double const EPS=0.0001;


double funct(double xn, double vn, double a1,double a2, double m)
{
	return((-(a1*vn+a2*(pow(vn,2))))/m);
}

double runge( double f(double,double,double,double,double), double xn, double vn, double h,double a1,double a2, double m)
{
	return (vn+h*(f(xn+h/2, vn+h/2*f(xn,vn,a1,a2,m),a1,a2,m)));
}

void correct (double xn, double vn, double a1,double a2, double m, double &h, double (*runge)(double(*func)(double,double,double,double,double),double, double,double,double,double,double))
{
	double xnn=xn;
	double v1=runge(funct,xn,vn,h,a1,a2,m);
	double v2=runge(funct,xn,runge(funct,xn,vn,h/2,a1,a2,m),h/2,a1,a2,m);
	double S=(v2-v1)/(2^2-1);
	double e=4*(v2-v1)/3;
	xn+=h;
	while (e>EPS)
	{
		h=0.5*h;
		v1=runge(funct,xnn,vn,h,a1,a2,m);
		v2=runge(funct,xnn,runge(funct,xnn,vn,h/2,a1,a2,m),h/2,a1,a2,m);
		S=(v2-v1)/(2^2-1);
		e=4*(v2-v1)/3;
		cout<<"arg: "<<xn<<' '<<"point vn+1: "<<v1<<' '<<"step: "<<h<<' '<<endl;
		
	}
	if (e<=EPS)
	{
		h=2*h;
		cout<<"Sufficiently accurate solution:   "<<"arg: "<<xn<<' '<<"point vn+1: "<<v1<<' '<<"step: "<<h<<' '<<endl;
	}	
}