#include <bits/stdc++.h>
using namespace std;

string s ;
typedef long long ll ;
const int mod = 1e9+7 ;
ll dp[100010][101][2];
int d ; 
ll calc(int idx , int sum , bool yes){
	if (idx == s.size()){
//		cout<<sum<<endl;
		if (sum== 0)
			return 1 ; 
		return 0 ;		
	}
	
	ll &ret = dp[idx][sum][yes] ; 
	if (ret != -1)return ret ; 
	
	ret = 0 ; 
	for (int i = 0 ; i<10 ; ++i){
		if (yes && i > s[idx]-'0')break;
		if (idx == 0){
			if (i == s[idx]-'0')
				ret += calc(idx+1 , (sum%d+i%d)%d , 1)%mod;
			else if (i<s[idx]-'0')
				ret += calc(idx+1 , (sum%d+i%d)%d , 0)%mod;
			else 
				break;
		}
		else {
			if (yes){
				if (i == s[idx]-'0')
						ret += calc(idx+1 , (sum%d+i%d)%d , 1)%mod;
				else 
						ret += calc(idx+1 , (sum%d+i%d)%d , 0)%mod;
			}else {
			
					ret += calc(idx+1 , (sum%d+i%d)%d , 0)%mod;
			}
		}
	
	}
	
	return ret%mod ; 
}

int main() {
	 
	cin>>s ; 
	scanf("%d" , &d) ; 
	memset(dp , -1 , sizeof dp) ; 
	int ans = calc(0 , 0 , 0) ; 
	printf("%lld" ,(ans-1+mod)%mod) ; 
	return 0;
}