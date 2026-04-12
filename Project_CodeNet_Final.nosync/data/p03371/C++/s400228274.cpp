#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    if(a+b<c*2) cout<<a*d+b*e<<endl;
    else if((d>e&&a>c*2)||(e>d&&b>c*2)) cout<<max(d,e)*2*c<<endl;
    else if(d>e) cout<<e*2*c+(d-e)*a<<endl;
    else cout<<d*2*c+(e-d)*b<<endl;
}
    