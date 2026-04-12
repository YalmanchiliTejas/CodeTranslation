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
	int n,k;
	string s, ans;

	cin >> n >> s >> k;
	
	ans = "";
	for(char c:s){
		if(s[k-1] != c){
			ans.append("*");
		} else {
			ans.push_back(c);
		}
	}

	cout << ans;

    return 0;
}
