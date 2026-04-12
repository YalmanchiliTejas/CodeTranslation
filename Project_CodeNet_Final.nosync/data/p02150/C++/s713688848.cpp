#include <bits/stdc++.h>
using LL = long long;
const LL MOD = 1e9+7;

using namespace std;


int main(){
    auto calc = [](LL A,LL B,LL C){
        LL ans = C;
        while(C > A){
          //  cout<<C<<endl;
            LL ins = (C-A)/(A-B)+1;
            if(ins == 0)break;
            ans += (B%MOD)*(ins%MOD);
            C = C + B*ins - ins*A;
            ans %= MOD;
        }
        if(C == A)ans += B%MOD;
        return ans%MOD;
    };/*
    for(int a = 0;a < 1000;a++){
        for(int b = 1;b < a;b++){
            for(int c = 0;c < 1000;c++){
                LL ans = c;
                LL w = c;
                while(w >= a){
                    LL q = w/a;
                    ans += q*b;
                    w+=q*b-q*a;
                }

                if(max(ans,0LL) != calc(a,b,c)){
                    cout<<a<<" "<<b<<" "<<c<<" "<<max(ans,0LL)<<" "<<calc(a,b,c)<<endl;
                }

              //  cout<<a<<" "<<b<<" "<<c<<" "<<ans<<endl;
            }
        }
    }
    */

    LL A,B,C;cin >>A >> B >> C;
    cout<<calc(A,B,C)<<endl;
}

