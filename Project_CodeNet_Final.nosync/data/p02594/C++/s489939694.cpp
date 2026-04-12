#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define F first
#define S second
#define all(v) v.begin(),v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

    ll t=1,tc;
    //cin>>t;
    for(tc=1;tc<=t;tc++){
      ll x;
      cin>>x;
      if(x>=30)cout<<"Yes";
      else cout<<"No";
    }
	return 0;
}