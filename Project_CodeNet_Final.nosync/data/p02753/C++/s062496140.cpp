//"I'll live the focused life, because it's the best kind there is" - Winifred Gallagher
#include<bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a << ": " << a << endl
using namespace std;
#define ll long long
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int> pii;
#define sz(a) int(a.size())
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) (v).begin(),(v).end()
#define fast cin.tie(0); ios::sync_with_stdio(false);

int main(){fast;
	string s; cin>>s;
	rep(i, sz(s) - 1){
		if(s[i] != s[i + 1]){
			puts("Yes");
			return 0;
		}
	}	
	puts("No");
}
