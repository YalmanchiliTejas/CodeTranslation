#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define vi vector<int>
#define INF (int)1e9
using namespace std;

int main() {
	int n;
	cin>>n;
	
	vi v(26,INF);
	REP(i,n){
		string s;
		cin>>s;
		
		vi cnt(26,0);
		REP(i,s.size()){
			cnt[s[i]-'a']++;
		}
		
		REP(i,26){
			v[i]=min(v[i],cnt[i]);
		}
	}
	
	string ans="";
	REP(i,26){
		REP(j,v[i]){
			ans+=('a'+i);
		}
	}
	
	cout<<ans<<endl;
}