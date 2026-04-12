#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
#define int long long
#define MOD 1000000007
typedef vector<int> vi;
typedef pair<int,int> pi;
#define inf 1e18
#define For(i,a,b) for (int i = a; i < b; i++)
#define Rep(i,a,b) for (int i = a; i <= b; i++)
#define ps(x,y) fixed << setprecision(y) << x 
#define pb push_back 
#define mp make_pair 
 
int32_t main()
{
    fast;
    int n, ans = 1, flag = 0; cin >> n;
    int a[n];
    For(i, 0, n) cin >> a[i];
    For(i, 1, n) {
        For(j, 0, i) {
            if(a[i] >= a[j]) flag = 1;
            else {flag = 0; break;}
        }
        if(flag) ans++;
    }

    cout << ans;

    
    
    return 0;
}