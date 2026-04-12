// This is the start of  template//
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int
#define vll vector<int>
#define pb push_back
#define pll pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
void input(){
#ifndef ONLINE_JUDGE 
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout); 
#endif
}
#define INF LONG_LONG_MAX
#define mod 1000000007
#define array(a,n) vll a(n); rep(i,0,n) cin>>a[i];
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define cases int t; cin>>t; while(t--)
#define printall(a) rep(i,0,a.size()) cout<<a[i]<<" "; cout<<endl;
//my template ends//
string s,temp,ans;
map<string,int>m;
int32_t main()
{
	ios_base::sync_with_stdio(0);
  	cin.tie(0);
 // 	input();
  	int n;
  	cin>>n;
  	if(n<30)
  	{
  		cout<<"No";
  	}
  	else
  		cout<<"Yes";
  
    return 0;
}

