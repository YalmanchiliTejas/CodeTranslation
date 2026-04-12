#include<bits/stdc++.h>
using namespace std;
long long a,b,c,x;
int main(){
    cin>>a>>b>>c;
    if(b>=a) return cout<<1<<endl,0;
    if(c>=b) return cout<<-1<<endl,0;
    if((a-b)%(b-c)) x=1;
    cout<<((a-b)/(b-c)+x)*2+1<<endl;
    return 0;
}