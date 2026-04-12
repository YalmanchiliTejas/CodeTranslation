#include "bits/stdc++.h"

using namespace std;

//int N,M,K,L,R,H,W;
long long int N,M,K,L,R,H,W;

//constexpr long long int MOD=1000000007;
//constexpr  int MOD=1000000007;
constexpr int MOD=998244353;
//constexpr long long int MOD=998244353;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s,t;
	cin>>s>>t;
	int ans=0;
	int cnt=0;
	vector<int>used(1000);
	vector<int>place(t.size());
	for(int i=0;i<s.size();i++){
		if(cnt<t.size()&&s[i]==t[cnt]){
			place[cnt]=i;
			cnt++;
		}
	}
	if(cnt<t.size()){
		cout<<"no\n";
		return 0;
	}
	place.push_back(s.size());
	for(int i=t.size()-1;i>=0;i--){
		cnt=i;
		for(int j=place[i]+1;j<place[i+1];j++){
			if(s[j]==t[i]){
				cout<<"no\n";
				return 0;
			}
		}
	}
	cout<<"yes\n";
	return 0;
}
