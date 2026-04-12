#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &x)
#define sz(v) (int) v.size()
#define pr(v) For(i, 0, sz(v)) {cout<<v[i]<<" ";} cout<<endl;
#define slld(x) scanf("%lld", &x)
#define all(x) x.begin(), x.end()
#define For(i, st, en) for(ll i=st; i<en; i++)
#define tr(x) for(auto it=x.begin(); it!=x.end(); it++)
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define ll long long
#define int long long
#define mp make_pair
#define F first
#define S second
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MOD 1000000007
#define INF 1000000000000000007LL

const int N = 100005;
 
// it's swapnil07 ;)
 
#ifdef SWAPNIL07
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
int begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
#else
#define endl '\n'
#define trace(...)
#define end_routine()
#endif

int d;

int dp[10005][105];

void precompute(){
    dp[0][0]=1;
    For(i, 0, 10){
        dp[1][i%d]++;
    }
    For(i, 2, 10001){
        For(j, 0, d){
            For(l, 0, 10){
                int mod = (j+l)%d;
                dp[i][mod]+=dp[i-1][j];
                dp[i][mod]%=MOD;
            }
        }
    }
}

signed main()
{
    fast
    #ifdef SWAPNIL07
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    string s; cin>>s;
    cin>>d;
    precompute();
    dp[0][0]=1;
    int cur = 0;
    int ans = 0;
    For(z, 0, sz(s)){
        int dig = s[z]-'0';
        int r = sz(s)-z-1;
        // rem length mod
        For(i, 0, dig){
            int mo = (cur+i)%d;
            mo = (d-mo)%d;
            ans += dp[r][mo];
            ans %= MOD;
        }
        cur = (cur+dig)%d;
    }
    if(cur!=0){
        ans = (ans-1+MOD)%MOD;
    }
    cout<<ans;
    return 0;
}



