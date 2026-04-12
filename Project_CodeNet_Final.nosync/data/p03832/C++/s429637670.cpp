#include<bits/stdc++.h>
#define pb           push_back
#define pii          pair<int,int>
#define vi           vector<int>
#define vpii         vector<pair<int,int>>
#define gph          map<int, vector<int>>
#define mp           make_pair
#define FOR(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD0(i, n) for (int i = (int)n; i >= 0; i--)
#define FORD1(i, n) for (int i = (int)n; i >= 1; i--)
#define FORS(i, n) for(; i < (int)(n); i++)
#define debug(X) { cout << #X << " = " << (X) << endl; }
#define printArr(A,n) { cout << #A << " = "; FOR(i,n) cout << A[i] << ' '; cout << endl; }
using namespace std;
#define int long long int

const int mod = (int)1e9 + 7;
int a, b, c, d;
int dp[1010][1010];
bool vis[1010][1010];
int fac[1010];
int infac[1010];
int p(int base, int ex){
    if(ex == 0)return 1;
    int sub = p(base, ex/2);
    sub *= sub;
    sub %= mod;
    if(ex & 1)sub *= base;
    sub %= mod;
    return sub;
}
long long inv(long long a, long long b = mod){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
}
int sol(int cnt, int len){
    if(cnt == 0)return 1;
    if(len > b)return 0;
    if(len * c > cnt)return 0;
    if(vis[cnt][len])return dp[cnt][len];
    vis[cnt][len] = true;
    int& ans = dp[cnt][len];
    ans = 0;
    int temp = p(fac[len], c);
    temp = inv(temp);
    int mult = infac[len];
    for(int num = c; num <= d; num++){
        if(num * len > cnt)break;
        int sub= sol(cnt - num*len, len+1) * temp; 
        sub %= mod;
        sub *= infac[num];
        sub %= mod;
        ans += sub;
        ans %= mod;
        temp *= mult;
        temp %= mod;
    }
    ans += sol(cnt, len + 1);
    ans %= mod;
//    cout << cnt << " " << len << " " <<ans <<endl;
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fac[0] =1;
    infac[0] = 1;
    FOR1(i, 1001)fac[i] = fac[i-1]*i, fac[i] %= mod, infac[i] = inv(fac[i]), infac[i] %= mod; 
    
    int n;cin >> n >> a >> b >> c >> d;
    int temp = sol(n, a);
    temp *= fac[n];
    temp %= mod;
    cout << temp;
}


