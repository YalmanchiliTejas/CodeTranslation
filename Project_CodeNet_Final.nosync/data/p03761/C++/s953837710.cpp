#include <bits/stdc++.h>
#define cinf(n,x) for(int i=0;i<(n);i++) cin >> x[i];
typedef long long int ll;
using namespace std;
const long long INF = 1LL<<60;

int main(){
	int n; cin >>n;
	vector<string> s(n);
	cinf(n,s);
	int cnt[n][26];
	for(int i=0;i<n;i++){
		for(int j=0;j<26;j++){
			cnt[i][j]=0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<s[i].size();j++){
			cnt[i][s[i][j]-'a']++;
		}
	}
	for(int i=0;i<26;i++){
		int Min=cnt[0][i];
		for(int j=0;j<n;j++){
			Min=min(cnt[j][i],Min);
			if(Min==0)break;
		}
		for(int j=0;j<Min;j++){
			cout << (char)('a'+i);
		}
	}
	cout << endl;
}