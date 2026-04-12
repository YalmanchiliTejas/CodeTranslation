#include<bits/stdc++.h>

using namespace std;

#define FOR(i,n) for(int i=0; i<n; ++i)
#define FORR(i,a,n) for(int i=a; i<n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<string> VS;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
 
int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
void printfv(VI a){ int n = a.size(); FOR(i, n) cout << a[i] << " "; }

int main(void){
	int n;
	cin >> n;

  	int a[n];
  	FOR(i, n){
  		cin >> a[i];
  	}
  	
  	int count = 1, obs = a[0];
  	FORR(i, 1, n){
  		if(obs <= a[i]){
  			obs = a[i];
  			count++;
  		}
  	}

  	cout << count;
    return 0;
}
