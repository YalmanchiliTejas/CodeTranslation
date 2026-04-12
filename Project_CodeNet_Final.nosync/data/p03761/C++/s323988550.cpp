#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	int n;cin>>n;
	int cnt[n][26]={};
	for(int i=0;i<n;i++){
		string s;cin>>s;
		rep(j,s.size()) cnt[i][s[j]-'a']++;
	}
/*	rep(i,n){
		rep(j,26) cout<<cnt[i][j]<<" ";
		cout<<"\n";
	}*/
	for(int i=0;i<26;i++){
		int sum=inf;
		for(int j=0;j<n;j++){
			sum=min(sum,cnt[j][i]);
		}
		
		if(sum!=inf) rep(k,sum) cout<<char('a'+i);
	}
	cout<<"\n";
	
}