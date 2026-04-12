#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int a,b,c;
    int sum1=0,sum2=0,sum3=0;
    int sum;
    int n,m;
    cin>>a>>b>>c>>n>>m;
    sum1=a*n+b*m;
    if(n>m){
        sum2=c*2*m+a*(n-m);
        sum3=c*2*n;
    }
    else{
        sum2=c*2*n+b*(m-n);
        sum3=c*2*m;
    }
    sum=min(sum1,sum2);
    sum=min(sum,sum3);
    cout<<sum<<endl;
}