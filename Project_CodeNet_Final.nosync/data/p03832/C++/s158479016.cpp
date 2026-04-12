#include <iostream>
#define ll long long
using namespace std;

int N, A, B, C, D;
ll mod=1000000007, memo[1010][1010];
bool se[1010][1010];
const int arm=1050;
ll fac[arm], finv[arm], inv[arm];
void COMinit(ll m){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for (int i=2; i<arm; ++i){
        fac[i]=(fac[i-1]*i)%m;
        inv[i]=m-(inv[m%i]*(m/i))%m;
        finv[i]=(finv[i-1]*inv[i])%m;
    }
}
ll COM(int n, int k, ll m){
    if(n<k) return 0;
    if(n<0 || k<0) return 0;
    return (fac[n]*((finv[k]*finv[n-k])%m))%m;
}
ll modpow(ll a, ll b, ll m){
    ll res=1, p=0, now=a;
    b %= (m-1);
    for(int i=0; b>p; ++i){
        if(b&((ll) 1<<i)){
            res=(res*now)%m;
            p |= ((ll) 1<<i);
        }
        now=(now*now)%mod;
    }
    return res;
}
ll modinv(ll a, ll m){
    return modpow(a, m-2, m);
}
ll moddiv(ll a, ll b, ll m){
    return (a*modinv(b, m))%m;
}


ll solve(int num, int group){
    if(!se[num][group]){
        if(num==0) memo[num][group]=1;
        else if(group==A){
            if(num%group==0 && (group*C<=num && num<=group*D)){
            	memo[num][group]=finv[num/group];
            	for(int i=0; i<num; i += group){
            		memo[num][group]=(memo[num][group]*COM(num-i, group, mod))%mod;
            	}
            }
            else memo[num][group]=0;
        }
        else{
            ll now=1;
            for(int i=0; group*i<=num && i<=D; ++i){
                if(i==0 || C<=i){
                    memo[num][group]=(memo[num][group]+(now*solve(num-group*i, group-1))%mod)%mod;
                }
                now=(now*moddiv(COM(num-group*i, group, mod), i+1, mod))%mod;
            }
        }
        se[num][group]=1;
    }
    return memo[num][group];
}


int main() {
	cin >> N >> A >> B >> C >> D;
	COMinit(mod);
	cout << solve(N, B) << endl;
	return 0;
}
