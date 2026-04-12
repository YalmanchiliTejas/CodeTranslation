#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll          long long int
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pair<int,int>>
#define mi          map<int,int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define rep(i,a,b)  for(i=a;i<b;i++)
#define inf         INT_MAX

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

using namespace std;
void solve()
{
    int n;
    cin>>n;
    if(n>=30)cout<<"Yes";
    else cout<<"No";
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
