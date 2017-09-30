#include "calculating.h"

void main()
{
	double xn,vn,h,a1,a2,m;
	char s;
	cout<<"Enter the argument:"<<endl;
	cin>>xn;
	cout<<endl;
	cout<<"Enter the point:"<<endl;
	cin>>vn;
	cout<<endl;
	cout<<"Enter step:"<<endl;
	cin>>h;
	cout<<endl;
	cout<<"Enter the const a1:"<<endl;
	cin>>a1;
	cout<<endl;
	cout<<"Enter the const a2:"<<endl;
	cin>>a2;
	cout<<endl;
	cout<<"Enter weight:"<<endl;
	cin>>m;
	cout<<endl;
	correct (xn,vn,a1,a2,m,h,runge);
	cout<<"Do you want change initial conditions?"<<endl;
	cin>>s;
	cout<<endl;
	while (s=='y')
	{
		cout<<"Enter new initial conditions:"<<endl;
		cout<<"Enter the argument:"<<endl;
		cin>>xn;
		cout<<endl;
		cout<<"Enter the point:"<<endl;
		cin>>vn;
		cout<<endl;
		cout<<"Enter step:"<<endl;
		cin>>h;
		cout<<endl;
		correct (xn,vn,a1,a2,m,h,runge);
		cout<<"Do you want change initial conditions?"<<endl;
		cin>>s;
		cout<<endl;
	}
	getch();
}