#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Endl "\n"
#define endl "\n"
#define in(x) int x;cin>>x;
#define all(x) x.begin(),x.end()
#define fo(i,n) for(int i=0;i<n;i++)
#define take(a,n) vector<int> a(n);fo(i,n)cin>>a[i];
#define print(a) for(auto x:a)cout<<x<<" ";cout<<endl;
#define eb emplace_back
#define pii pair<int,int>


void fastio()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
}

void solve()
{
	in(x);
	if(x>=30)cout<<"Yes\n";
	else cout<<"No\n";
}

int32_t main()
{
    
    
        solve();
    return 0;
}