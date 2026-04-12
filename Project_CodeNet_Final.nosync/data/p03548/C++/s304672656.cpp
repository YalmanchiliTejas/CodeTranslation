#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){
    optimizar_io
    int a,b,c,ans=0; cin>> a >> b >> c;
    int aux=c;
    while(aux<=a){
        aux+=b; aux+=c;
        if(aux<=a)ans++;
    }
    cout<<ans<<endl;

}

