#include <bits/stdc++.h>

template<typename T>
constexpr T modpow(T a,T n,T mod=1000000007){//(a^n)%MOD
    T ret=1;
    while(n>0){
        if((n&1)!=0){//n%2==1
            ret=ret*a%mod;
        }
        a=a*a%mod;
        n=n/2;
    }
    return ret;
}

std::vector<long long> fac;
std::vector<long long> ifac;
long long MOD=1000000007;
template <typename T>
T modcomb(T a, T b,T MOD=1000000007){
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    long long tmp = ifac[a-b]* ifac[b] % MOD;
    return tmp * fac[a] % MOD;
}

void combinit(int maxn){
    fac.resize(maxn);
    ifac.resize(maxn);
    fac[0] = 1;
    ifac[0] = 1;
    for(long long i = 0; i<maxn; i++){
        fac[i+1] = fac[i]*(i+1) % MOD;
        ifac[i+1] = ifac[i]*modpow(i+1, MOD-2) % MOD;
    }
}

using namespace std;
using ll=long long;

bool lsgeq(string s,string t){
    if(s.size()>t.size())return true;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]>t[i])return true;
        if(s[i]<t[i])return false;
    }
    return true;
}

int main(){
    combinit(2000);
    string n;
    cin>>n;
    int k;
    cin>>k;
    if(n.size()<k){
        cout<<0<<endl;
        return 0;
    }
    ll ans=0;
    ll c=1;
    for (int j = 0; j < k; ++j) {
        c*=9;
    }
    for (int i = k; i < n.size(); ++i) {
        ans+=c*modcomb(i-1,i-k);
    }
    if(k==3){
        for (int i = 0; i < 9; ++i) {
            string t(n.size(),'0');
            t[0]+=(i+1);
            for (int j = n.size()-1; j >= 1; --j) {
                for (int k = j-1; k >= 1; --k) {
                    for (int l = 1; l <= 9; ++l) {
                        for (int m = 1; m <= 9; ++m) {
                            t[j]+=l;t[k]+=m;
                            if(lsgeq(n,t)){
                                ++ans;
                            }
                            
                            t[j]='0';t[k]='0';
                        }
                    }
                }
            }
        }
    }
    else if(k==2){
        for (int i = 0; i < 9; ++i) {
            string t(n.size(),'0');
            t[0]+=(i+1);
            for (int j = n.size()-1; j >= 1; --j) {
                for (int l = 1; l <= 9; ++l) {

                        t[j]+=l;
                        if(lsgeq(n,t)){
                            ++ans;
                        }
                        t[j]='0';

                }
            }
        }
    }
    else if(k==1){
        for (int i = 0; i < 9; ++i) {
            string t(n.size(), '0');
            t[0] += (i + 1);
            if(lsgeq(n,t)){
                ++ans;
            }
            
        }
    }

    cout<<ans<<endl;
    return 0;
}