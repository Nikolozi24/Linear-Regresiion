#include <iostream>
#include<cmath>
using namespace std;
double calculateSum(double *x , int size){
	double sum=0;
	for(int i=0; i<size; i++){
		sum+=x[i];
	}	
	return sum;
}
double calculateB1(double *xy , double *x , double *y , double *xx , int size){
        return ((size*calculateSum(xy, size)-(calculateSum(x,size)*calculateSum(y,size)))/(size*calculateSum(xx,size) - pow(calculateSum(x,size),2)));
}

double CalculateB0(double *y , double b1 ,  double *x , int size){
    return (calculateSum(y,size) - (b1*calculateSum(x,size)))/size;
}
double CalculateY(double B1, double x, double B0 ){
    return (B1*x+B0);
}

int main()
{
    int Size;
    cout<<" gtxovt shemoitanet wertilebis raodenoba: ";
    cin>>Size;
    double x[Size] , y[Size] ,xy[Size], X , B1,B0,Y, xx[Size] ,PrognozeX, PrognozeY;
    int i;

    for(i=0; i<Size; i++){
        double X, Y;
        cout<<"x: ";
        cin>>X;
        cout<<"y: ";
        cin>>Y;
        x[i]=X;
        y[i]=Y;
        xy[i]= X*Y;
        xx[i]= X*X;
    }

    B1 = calculateB1(xy,x,y,xx,Size);
    B0 = CalculateB0(y , B1 , x , Size);
    cout<<"gtxovt shemoitanot X prognozisatvis:  ";
    cin>>PrognozeX;
    PrognozeY = CalculateY(B1 , PrognozeX , B0);
    cout<<"\n tqveni shemotanili X = "<<PrognozeX<<endl;
    cout<<" B1 =  "<<B1<<"\n";
    cout<<" B0 = "<<B0<<"\n";
    cout<<" Wrfis gantolebaa: Y="<<B1<<"X+"<<B0<<"\n";
    cout<<" Y = "<<PrognozeY<<"\n";
   
}