#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
const int inf = 0x3f3f3f3f;
const ll linf = 123456789012345678;
const ll mod = 1000000007;
#pragma GCC optimize("Ofast")
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << x << endl
#define sz(x) ((int)(x).size())


int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vi colors(100001, -1);
    for(int i = 0; i < n; i++){
        int lo = 0, hi = 100001;
        while(lo+1<hi){
            int mid = (lo+hi-1)/2;
            if(colors[mid] >= a[i]){
                lo = mid + 1;
            }
            else{
                hi = mid + 1;
            }
        }
        colors[lo] = a[i];
    }
    int ans = 0;
    for(int i = 0; i < 100001; i++) ans += colors[i]!=-1;
    cout << ans << "\n";
}