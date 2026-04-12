#include<iostream>
#include<string>
using namespace std;
int n;
long long x;
long long layers[51]; 
long long ps[51];
long long func(int n,long long x)
{
    if(n==0) return 1;
    if(x<=1) return 0;
    else if(x<=1+layers[n-1]) return func(n-1,x-1);
    else if(x==layers[n-1]+2) return ps[n-1]+1;// B pre p
    else if(x>=2+layers[n-1]&&x<=2*layers[n-1]+2) return ps[n-1]+func(n-1,x-2-layers[n-1])+1;
    else if(x==3+2*layers[n-1]) return 2*ps[n-1]+1;
}
int main()
{
    ios::sync_with_stdio(false);
    layers[0]=1;
    ps[0]=1;
    for(int i=1;i<=50;i++)
    {
        layers[i]=2*layers[i-1]+3;
        ps[i]=2*ps[i-1]+1;// B pre p pre B  2*pre+1
    }
    while(cin>>n>>x)
    {
       cout<<func(n,x)<<endl;
    }
}