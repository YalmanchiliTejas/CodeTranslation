#include"bits/stdc++.h"
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep3(i,m,n) for(int (i)=m;(i)<=(n);(i)++)
#define rep3rev(i,m,n) for(int (i)=m;(i)>=(n);(i)--)
#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

ll P[55], N[55];

ll f(int i, ll x){
  	if(i==0) return x;
  	else if(x==0 || x==1) return 0;
  	else if(x==N[i]) return P[i]; 
  	else if(x<=N[i-1]+1) return f(i-1,x-1);
  	else if(x<=N[i]-1) return 1+P[i-1]+f(i-1,x-2-N[i-1]);
}

void Main()
{
	int n; ll x;
  	cin >> n >> x;
  	
  	// P[i] = レベル i バーガーの P の数
  	// N[i] = レベル i バーガーの全体数
  
  	// レベル 0 バーガー P
  	// レベル 1 バーガー B[P]P[P]B  	
  	// レベル 2 バーガー B[BPPPB]P[BPPPB]B
  	// レベル 3 バーガー B[BBPPPBPBPPPBB]P[BBPPPBPBPPPBB]B
  
  	N[0] = 1;
  	P[0] = 1;
  	int i = 0;
  	while(i < n) {
      	N[i+1] = 3+2*N[i];
      	P[i+1] = 1+2*P[i];
      	i++;
    }
  	
	ll ans = f(n, x);  
  	cout << ans << endl;
	return;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
	return 0;
}