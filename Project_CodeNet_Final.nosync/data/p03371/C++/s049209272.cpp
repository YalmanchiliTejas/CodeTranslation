#include <bits/stdc++.h>
using namespace std;

int main(){
    long a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    long ah;
    long long ak;
    if(d>e){
        ah=d;
        ak=((2*e)*c)+((d-e)*a);
    }
    else{
        ah=e;
        ak=((2*d)*c)+((e-d)*b);
    }
    long val=(c)*(2*ah);
    long long val1=(d*a)+(b*e);
    if(ak<=val&&ak<=val1) cout<<ak<<endl;
    else if(val<=val1&&val<=ak) cout<<val<<endl;
    else cout<<val1<<endl;
    return 0;
}