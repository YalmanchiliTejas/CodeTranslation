#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI pair<int,int>
#define ff first
#define ss second
#define endl '\n'
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
//#include "debug.cpp"

string s;
int k;

int dp[101][2][4];
int rec(int p,int c,int kk) {
	//cout<<p<<" "<<c<<" "<<kk<<endl;
	
	if(p>s.size() or kk>k)
		return 0;

	if(p==s.size()){
		return (k==kk);
	}

	int &tmp=dp[p][c][kk];
	if(tmp!=-1)
		return tmp;
	tmp=0;
	if(c){
		for(int i=0;i<=s[p]-'0';i++)
			tmp+=rec(p+1,(i==s[p]-'0'),kk+(i>0));
	}
	else{
		for(int i=0;i<=9;i++)
			tmp+=rec(p+1,0,kk+(i>0));
	}
	return tmp;
}


int32_t main()
{
	boost;
  	if(0){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif // ONLINE_JUDGE
    }
	cin>>s;
	cin>>k;
	memset(dp,-1,sizeof dp);
	int ans=rec(0,1,0);
	cout<<ans<<endl;
}