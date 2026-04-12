#include<bits/stdc++.h>
using namespace std;
#define TRACE
 
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define ll long long
#define pb push_back
#define mb make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;
int dp[10123][105][2];
string s;
int d;
int ways(int i,int sum,int flag){
	if(i==s.length()){
		if(sum==0)
			return 1;
		return 0 ;

	}
	if(dp[i][sum][flag]!=-1)
		return dp[i][sum][flag];
	int lim = 9;
	if(flag==0)
		lim = s[i]-'0';
	int ans = 0;
	for(int j = 0 ; j<=lim;j++){
		if(j==lim and flag==0)
			ans+=ways(i+1,(sum+j)%d,0);
		else
			ans+=ways(i+1,(sum+j)%d,1);
		ans%=mod;
	}
	return dp[i][sum][flag]=ans;
}
int main(){
	IOS;
	cin >> s;
	cin >> d;
	memset(dp,-1,sizeof(dp));
	int ans = ways(0,0,0);
	cout << (ans-1+mod)%mod << endl;


	return 0;
}


