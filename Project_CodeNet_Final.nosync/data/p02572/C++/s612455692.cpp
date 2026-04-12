#include <bits/stdc++.h>
using namespace std;

#define for0(i, n) for (int i = 0; i < (int)(n); ++i) 
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) 
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i)
#define deb(x) cout << #x << "= " << x << endl
#define pb push_back
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define tr(x) for(auto it = x.begin(); x != x.end(); it++)
#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

int main() {
    fast;
    int t=1;
    while(t--){
        //begin code here
        int n; cin>>n;
        ll arr[n]; ll sum=0;
        for0(i,n){
            cin>>arr[i];
            sum+=arr[i];
            sum%=MOD;
        }
        ll ans=0;
        for0(i,n){
            sum-=arr[i];
            if(sum<0){
                sum+=MOD;
            }
            ans+=(sum*arr[i]);
            ans%=MOD;
        }
        cout<<ans;
    }
}