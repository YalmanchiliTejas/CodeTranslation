#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    //float f;
    string s;
    int m,n,o;
    //vector <float> f(10);
    //char a,b,c;
    int i=0,j,sum=0,dir=1,pos;
    //long long int m,n,o,total=0;
    cin>>n;
    int *num=new int [n];
    if(n%2==0) dir=1;
    else dir=-1;
    for(i=0;i<n;i++)
    {
        pos=n/2+(i+1)/2*dir;
        cin>>num[pos];
        dir=-dir;
    }
    for(i=0;i<n;i++) cout<<num[i]<<' ';
    delete [] num;
    return 0;
}

