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

void Main()
{
	int n; ll x;
  	cin >> n >> x;
  	
  	// B[i] = レベル i バーガーの B の数
  	// P[i] = レベル i バーガーの P の数
  	// N[i] = レベル i バーガーの全体数
  
  	// レベル 0 バーガー P
  	// レベル 1 バーガー B[P]P[P]B  	
  	// レベル 2 バーガー B[BPPPB]P[BPPPB]B
  	// レベル 3 バーガー B[BBPPPBPBPPPBB]P[BBPPPBPBPPPBB]B
  
  	ll B[55], P[55], N[55];
  	N[0] = 1;
  	B[0] = 0;
  	P[0] = 1;
  	int i = 0;
  	while(i < n) {
      	N[i+1] = 3+2*N[i];
      	B[i+1] = 2+2*B[i];
      	P[i+1] = 1+2*P[i];
      	i++;
    }
  	//cout << i << ": " << B[i] << " " << P[i] << " " << N[i] << endl;
  	
  	auto f = [&](int xx){
    	if(xx<=4) return xx-1;
      	if(xx==5) return 3;
    };
  	
  	// 現在 N[i] >= x > N[i-1]
	ll ans = 0;
  	while(x>0){
      	if(i == 1){
			ans += f(x);
          	break;
        }
      	else if(x == N[i]){
        	ans += P[i];
          	break;
        }
      	else if(x>N[i-1]+1){
      		// i-1 バーガーの下 x 個問題に帰着
        	ans += P[i-1]+1;
          	x -= 2 + N[i-1];
        }else{
          	x--;
        }
        i--;
      	//cout << i << " " << x << " " << ans << endl;
    }
  
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