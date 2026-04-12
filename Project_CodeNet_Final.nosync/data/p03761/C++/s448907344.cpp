#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

int main(){
	
	int n;
	cin>>n;
	
	vector<int> cnt(26,Inf);
	
	for(int i=0;i<n;i++){
		string S;
		cin>>S;
		vector<int> S_cnt(26,0);
		
		for(int j=0;j<S.size();j++){
			S_cnt[S[j]-'a']++;
		}
		
		for(int j=0;j<26;j++){
			cnt[j] = min(cnt[j],S_cnt[j]);
		}
	}
	
	string ans = "";
	for(int i=0;i<26;i++){
		for(int j=0;j<cnt[i];j++){
			ans += (char)('a'+i);
		}
	}
	
	cout<<ans<<endl;
	
    return 0;
}

