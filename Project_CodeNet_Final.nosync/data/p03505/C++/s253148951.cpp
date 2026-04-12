#include<bits/stdc++.h>
using namespace std;
long long k,a,b,ji;               
int main()
{
    cin>>k>>a>>b;
    if(a>=k) {cout<<1<<"\n";return 0;}
    if(b>=a) {cout<<-1<<"\n";return 0;}
    if((k-a)%(a-b)>=1) ji=1;
    cout<<((k-a)/(a-b)+ji)*2+1;
    cout<<"\n";
    return 0;
}