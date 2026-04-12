#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    long double a1,a2;
    cin>>a1>>a2;
    printf("%.10Lf",a1*a2/(a1+a2));
    return 0;
}