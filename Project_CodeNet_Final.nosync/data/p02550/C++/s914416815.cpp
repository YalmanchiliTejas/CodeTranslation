#include <bits/stdc++.h>
#include <string>

#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()

typedef long long ll;

const ll MOD=1000000007ll;
const int MAX=5100000;

using namespace std;

int inputValue(){
    int a;
    cin >> a;
    return a;
};

void inputArray(int * p, int a){
    for(int i=0;i<a;i++){
        cin >> p[i];
    }
};

void inputVector(vector<int> * p, int a){
    for(int i=0;i<a;i++){
        int input;
        cin >> input;
        p -> push_back(input);
    }
}

ll fact[MAX], fact_inv[MAX];

ll power(ll a, ll b){
	ll res=1;
	while(b>0){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return res;
}

// nCr
ll comb(ll n, ll r){
	ll t=1000000;
	fact[0]=1;
	    for(int i=0;i<t;i++){ fact[i+1]=fact[i]*(i+1)%MOD;}
	fact_inv[t]=power(fact[t], MOD-2);
	for(int i=0;i<t;i++){ fact_inv[i]=fact_inv[i+1]*(i+1)%MOD;}
	return (fact[n]*fact_inv[r])%MOD*fact_inv[n-r]%MOD;
}

int i,j,k,tmp;
ll ans = 0;

int main()
{
	cin.tie(0);	ios::sync_with_stdio(false);

  ll N; cin >> N;
  ll X, M; cin >> X >> M;
  ll sum = 0; ll ans = 0; ll start = 0; ll end = 0;

  ll chk[M+1]; rep(i,M+1){chk[i]=0;}
  ll tmp[M+1]; rep(i,M+1){tmp[i]=0;}
  tmp[1]=X; chk[X]=1; sum = X;
  ll circle = 0;

  for(int i=2;i<=M;i++){
	ll cal = tmp[i-1] * tmp[i-1] % M;
	if(cal == 0){cout << sum << endl; return 0;}
	if(chk[cal]>0){end = i-1; start = chk[cal]; break;}
	chk[cal]=i; tmp[i]=cal; sum += cal;
	if(i == N){cout << sum << endl; return 0;}
  }

  ans += sum;
  N -= end; circle = end - start + 1;
  for(int i=1; i<start; i++){sum -= tmp[i];}
  ans += (N / circle) * sum;
  
  if(N % circle > 0){
	  ll end2 = N % circle;
	  for(int i=1; i <= end2;i++){
		  ans += tmp[i+start-1];
	  }
  }

  cout << ans << endl;

  return 0;
}
