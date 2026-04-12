#include <bits/stdc++.h>

#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i,l,r) for (int i=l;i<=r;i++)
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ll long long
#define mod 1000000007
#define random_jbt mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;

int main(){
    int n,h=0,ans=0;
    cin>>n;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        if (x>=h)ans++;
        h=max(h,x);
    }
    cout<<ans;
    return 0;
}
