#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define MOD (1000000007ll)

bool conccomp(int x, int y, int p, int q){
	return (p*y>x*q);
}

int main(void){
	int n,i,j,cnt[55][26],l;
	string s[55],ans;
	fill(cnt[0],cnt[55],0);
	cin >> n;
	for(i=0; i<n; ++i){
		cin >> s[i];
		for(j=(s[i].length()-1); j>=0; --j){
			cnt[i][s[i][j]-'a']++;
		}
	}
	for(j=0; j<26; ++j){
		l = INF;
		for(i=0; i<n; ++i){
			l = min(cnt[i][j],l);
		}
		for(i=0; i<l; ++i){
			ans += (char)('a'+j);
		}
	}
	cout << ans << endl;
	return 0;
}
