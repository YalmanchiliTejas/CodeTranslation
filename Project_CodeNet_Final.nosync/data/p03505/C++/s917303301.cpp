#include<bits/stdc++.h>
using namespace std;
long long a,b,sum,k;
int main()
{
    cin>>k>>a>>b;
    if(a>=k) 
    {cout<<1<<endl;return 0;}
    if(b>=a) return cout<<-1<<endl,0;
    if((k-a)%(a-b)>=1)  
    sum=1;
    cout<<((k-a)/(a-b)+sum)*2+1<<endl;
    return 0;
}