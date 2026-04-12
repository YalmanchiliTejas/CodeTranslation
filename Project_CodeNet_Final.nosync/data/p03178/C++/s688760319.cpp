#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=1e9+7;

ll dp[10001][101][2];
string s;

ll calculate(ll d,ll pos,ll sum,bool tight){
	if(pos==s.length()){
		return sum%d==0;
	}
	if(dp[pos][sum][tight]==-1){
		ll ub=9;
		ll count=0;
		if(tight)
			ub=s[pos]-'0';
		for(ll i=0;i<=ub;i++){
			count=(count+calculate(d,pos+1,(sum+i)%d,tight&(i==ub)))%M;
		}
		dp[pos][sum][tight]=count;
	}
	return dp[pos][sum][tight];
}

int main(){
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);	
 ll d;
 memset(dp,-1,sizeof dp);
 cin>>s>>d;
 //cout<<s<<endl;
 cout<<(calculate(d,0,0,1)-1+M)%M<<endl;;
 return 0;
}

