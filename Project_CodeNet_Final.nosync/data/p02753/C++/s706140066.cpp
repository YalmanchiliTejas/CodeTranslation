#include<bits/stdc++.h>
#define int long long
#define M 998244353
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define zero(dp) memset(dp,0,sizeof(dp))
#define pb emplace_back
#define sublime 
using namespace std;
int32_t main(){
ios
int t=1;
//cin>>t;
while(t--)
{
	string s;cin>>s;
	set<char> st;
	for(int i=0;i<3;i++)st.insert(s[i]);
	if(st.size()>1)cout<<"Yes\n";
	else cout<<"No";
}
}