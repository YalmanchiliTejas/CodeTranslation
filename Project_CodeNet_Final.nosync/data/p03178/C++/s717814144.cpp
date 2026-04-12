#include<bits/stdc++.h>
#include<algorithm>
#include <assert.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define ll long long 
#define sum(a,b) a=a+b
#define repn(a,b,c) for(int a = b ; a>=c ; a--)
#define mem(a,b) memset(a,b,sizeof(a))

string s;
ll d;
int mod = 1e9 + 7;
ll memo[10001][101][2];

ll dp(ll pos ,ll sum , bool limit){

	if(pos >= s.size()){
		return sum == 0;
	}


	if(memo[pos][sum][limit]!=-1){
		return memo[pos][sum][limit];
	}

	ll num = (int)s[pos]-'0';

	if(limit == true){
		num = 9;
	}

	ll ans = 0;

	rep(i,0,num){
		if(i == (s[pos]-'0')){
			ans = ans + dp(pos+1,(sum + i)% d ,limit);
		}else{
			ans = ans + dp(pos+1,(sum+i)%d , true);
			
		}

		ans=ans%mod;
	}


	return memo[pos][sum][limit] = ans;

}


int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	mem(memo,-1);

	cin>>s>>d;

	ll ans = dp(0,0,0) % mod;
	ans -= 1;
	if(ans < 0) ans += mod;
	cout<<ans<<endl;

	return 0;
}