#include <bits/stdc++.h>
using namespace std;
#define int long long int
mt19937 rng(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int N=3005;
#define M 998244353
#define double long double
#define BINF 10000000000001
#define init(arr,val) memset(arr,val,sizeof(arr))
#define MAXN 5000004
#define deb(x) cout << #x << " " << x << "\n";
const int LG = 22;

int suf[N];
int dp[N][N][2];
int n, S, a[N];

int foo(int pos, int sum, int f){
    if(sum < 0)
        return 0;
    if(sum == 0){
        return n - pos + 1;
    }
    if(pos == n){
        if(sum == 0)
            return 1;
        return 0;
    }
    if(dp[pos][sum][f] != -1){
        if(f == 0){
            suf[pos] = (suf[pos] + dp[pos][sum][f]) % M;
        }
        return dp[pos][sum][f];
    }

    int x = foo(pos + 1, sum, f);
    int y = foo(pos + 1, sum - a[pos], f | 1);

    if(f == 0){
        suf[pos] = (suf[pos] + y) % M;
    }

    return dp[pos][sum][f] = (x + y) % M;
}



#undef int 
int main() {
#define int long long int
ios_base::sync_with_stdio(false); 
cin.tie(0); 
cout.tie(0);


    cin >> n >> S;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    init(dp, -1);

    int ans = foo(0, S, 0);
    for(int i = n - 2; i >= 0; i--){
        suf[i] = (suf[i] + suf[i + 1]) % M;
    }

    ans = 0;
    for(int i = 0; i < n; i++)
        ans = (ans + suf[i]) % M;
    cout << ans << endl;
    
    

return 0;  
}
