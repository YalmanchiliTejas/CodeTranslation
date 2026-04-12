#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<n;(i)++)

int main(){

	int n;
	cin >> n;
	string S[n];
	rep(i,n) cin >> S[i];

	int cnt[26] = {};
	for(int j=0; j<S[0].length(); j++) cnt[S[0][j]-'a']++;
	rep(i, n) {
		int tmp[26] = {};
		for(int j=0; j<S[i].length(); j++) tmp[S[i][j]-'a']++;
		for(int j=0; j<26; j++)cnt[j] = min(cnt[j],tmp[j]);
	}
	rep(i, 26)
		rep(j,cnt[i]) printf("%c", 'a'+i);
	printf("\n");
}