#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void){
    ll k,a,b;
    cin>>k>>a>>b;
    if(a>=k){
        cout<<1<<endl;
    }else if(a<=b){
        cout<<-1<<endl;
    }else{
        ll x = (k-a)/(a-b);
        if(x*(a-b)>=k)cout<<x*2<<endl;
        else if(x*(a-b)+a>=k)cout<<x*2+1<<endl;
        else cout<<x*2+3<<endl;
    }


    return 0;
}
