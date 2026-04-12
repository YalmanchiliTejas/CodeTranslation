//       Author: Mostafa Mounir Shehab
 
#include <bits/stdc++.h>
using namespace std;
 
#define PI  acos(-1)
#define EPS (1e-10)
#define endl "\n"
#define SZ(v) (int)(v.size())
#define IO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL);
typedef long long ll;
typedef long double ld;
 

 
ll MOD=1e9 + 7;
ll OO=1e9 + 10;
const int N=1e4 + 5,M=1e2 + 5;

ll dp[N][M][2];



int n,m,k,cnt,SU,idx,len,MN,MX,T;
int l,r,mid;
int a,b,c;
string str;

ll Solve(int idx,int sum,bool flage){
	sum%=k;
	if(idx == SZ(str))
		return !sum;
	
	ll &ret = dp[idx][sum][flage];
	if(~ret)
		return ret;
	ret = 0;
	
	int en = flage ? str[idx]-'0' : 9;
	for(int i=0;i<=en;++i)
		ret+=Solve(idx+1,sum+i,flage&(i == str[idx]-'0'));
		
	
	return ret = ret%MOD;
}


int main(){
	
	IO
	memset(dp,-1,sizeof dp);
	
	cin>>str>>k;
	
	
	cout<<(Solve(0,0,true)-1+MOD)%MOD<<endl;

	
}
