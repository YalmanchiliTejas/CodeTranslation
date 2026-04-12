#include <iostream>
using namespace std;
typedef long long ll;
ll inf = 1e9+7;
ll func[1010] = {0};
ll inv[1010] = {0};

ll mult(ll n, ll m){
    if(m==0) return 1;
	if(m==1) return n%inf;
	else if(m%2==0){
		ll t = mult(n,m/2);
		return (t*t)%inf;
	}else{
		ll t = mult(n,m-1);
		return (t*n)%inf;
	}
}

void factorial(ll N){
	for(ll i=0;i<=N;i++){
		if(i==0){
			func[i] = 1;
			inv[i] = 1;
		}
		else{
			func[i] = (i*func[i-1])%inf;
			inv[i] = mult(func[i],inf-2);
		}
	}
}

ll comb(ll n,ll k){
	if(n<k) return 0;
	if(n<0 || k<0) return 0;
	else return (((func[n]*inv[k])%inf)*inv[n-k])%inf;
}

ll permutation(ll n,ll k){
    return (comb(n,k)*func[k])%inf;
}

int N,A,B,C,D;
ll dp[1010][1010] = {};

int main(){
    cin >> N >> A >> B >> C >> D;
    factorial(N);
    for(int i=0;i<=B;i++) dp[i][0] = 1;
    ll ans = 0;
    for(int i=A;i<=B;i++){
        for(int j=1;j<=N;j++){
            for(int k=0;k<=D;k++){
                if(j-i*k<0) break;
                if(0<k && k<C) continue;
                ll v = (mult(inv[i],k)*inv[k])%inf;
                ll r = (permutation(N-j+i*k,i*k)*v)%inf;
                (dp[i][j] += (dp[i-1][j-i*k]*r)%inf)%=inf;
            }
        }
//        (ans += dp[i][N])%=inf;
    }
/*    for(int i=0;i<=B;i++){
        for(int j=0;j<=N;j++){
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }*/
    // cout << dp[1][1] << endl;
    cout << dp[B][N] << endl;
}
