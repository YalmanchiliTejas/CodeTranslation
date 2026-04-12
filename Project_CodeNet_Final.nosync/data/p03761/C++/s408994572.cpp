#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<int, int> P;
typedef pair<int, P> E;
#define MOD (1000000007ll)
#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	b += MOD;
	a += b;
	a %= MOD;
}

int main(void){
	int n,i,tmp[26],ans[26],j;
	string s;
	cin >> n;
	fill(ans,ans+26,INF);
	for(i=0; i<n; ++i){
		cin >> s;
		fill(tmp,tmp+26,0);
		for(j=s.l_ength()-1; j>=0; --j){
			++tmp[s[j]-'a'];
		}
		for(j=0; j<26; ++j){
			ans[j] = min(ans[j],tmp[j]);
		}
	}
	for(j=0; j<26; ++j){
		for(i=0; i<ans[j]; ++i){
			cout << ((char)('a'+j));
		}
	}
	cout << endl;
	return 0;
}
