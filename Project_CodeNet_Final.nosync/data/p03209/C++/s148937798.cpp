#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define lp(i,s,f) for(ll i = s; i < ll(f); i++)
#define inF freopen("input.in", "r", stdin);
#define outF freopen("output.in", "w", stdout);
#define endl '\n'
#define MOD 1000000007
#define mm(arr) memset(arr, 0, sizeof(arr))
#define F first
#define S second
#define int ll

int patties[51];
int sz[51];
int calc(int n, int x){
    if(n == 0){
        if(x <= 0){
            return 0;
        }
        else{
            return 1;
        }
    }
    if(x <= sz[n - 1] + 1){
        return calc(n - 1, x - 1);
    }
    return patties[n - 1] + calc(n - 1, x - sz[n - 1] - 2) + 1;
}
int32_t main(){
    FAST
    int n, x; cin >> n >> x;
    patties[0] = 1;
    sz[0] = 1;
    for(int i = 1; i <= n; i++){
        sz[i] = sz[i - 1]*2 + 3;
        patties[i] = patties[i - 1]*2 + 1;
    }
    cout << calc(n, x);
    return 0;
}
