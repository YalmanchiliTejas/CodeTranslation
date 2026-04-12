#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef vector<int> vi;
typedef pair<int, int> pi;
#define SQ(a) (a) * (a)
#define mod 1000000007
#define w(x) int x; cin>>x; while(x--)
#define deb(x) cout << #x << " = " << x << '\n'
#define deb2(x, y) cout << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"
 
void solve(){
    int n;
    cin>>n;
    ll int a[n];
    ll int sum=0;

    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sum=0;
    ll int curr=0;
    ll int ans=0;
    for(int i=n-1;i>=0;i--){
        ans= (ans+a[i]*sum)%mod;
        sum= (sum+a[i])%mod;
    }
    cout<<ans;
}
 
int main(int argc, char const *argv[])
{
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}
