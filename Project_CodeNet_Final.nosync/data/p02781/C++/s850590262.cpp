#include <bits/stdc++.h>
using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#define rep(i,a,n)    for(int i=a; i<=n; ++i)
#define rep1(i,a,n)   for(int i=a; i>=n; --i)
#define pb            push_back
#define mp            make_pair
#define int           unsigned long long
#define fr            first
#define sc            second
#define vc            vector
#define sz(v)         (int)v.size()
#define all(x)        (x).begin(),(x).end()
#define rall(x)       (x).rbegin(),(x).rend()
#define N             (int)(1e6+5)
// #define M             1000000007
#define MM            998244353
#define PI            3.14159265358979
#define INF           1000000000000000

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<int,int> mii;

int n,m,ans; string str;

const int M = 105; 
  
// states - position, count, tight 
int dp[M][M][2]; 
  
// K is the number of non zero digits 
int K; 
  
// This function returns the count of 
// required numbers from 0 to num 
int countInRangeUtil(int pos, int cnt, int tight, 
                     vector<int> num) 
{ 
    // Last position 
    if (pos == num.size()) { 
        // If count of non zero digits 
        // is less than or equal to K 
        if (cnt <= K) 
            return 1; 
        return 0; 
    } 
  
    // If this result is already computed 
    // simply return it 
    if (dp[pos][cnt][tight] != -1) 
        return dp[pos][cnt][tight]; 
  
    int ans = 0; 
  
    // Maximum limit upto which we can place 
    // digit. If tight is 1, means number has 
    // already become smaller so we can place 
    // any digit, otherwise num[pos] 
    int limit = (tight ? 9 : num[pos]); 
  
    for (int dig = 0; dig <= limit; dig++) { 
        int currCnt = cnt; 
  
        // If the current digit is nonzero 
        // increment currCnt 
        if (dig != 0) 
            currCnt++; 
  
        int currTight = tight; 
  
        // At this position, number becomes 
        // smaller 
        if (dig < num[pos]) 
            currTight = 1; 
  
        // Next recursive call 
        ans += countInRangeUtil(pos + 1, currCnt, 
                                currTight, num); 
    } 
    return dp[pos][cnt][tight] = ans; 
} 
  
// This function converts a number into its 
// digit vector and uses above function to compute 
// the answer 
int countInRange(vi num) 
{ 
    // Initialize dp 
    memset(dp, -1, sizeof(dp)); 
    return countInRangeUtil(0, 0, 0, num); 
}
int countIniRange(int x) 
{ 
    vector<int> num; 
    while (x) { 
        num.push_back(x % 10); 
        x /= 10; 
    } 
    reverse(num.begin(), num.end()); 
  
    // Initialize dp 
    memset(dp, -1, sizeof(dp)); 
    return countInRangeUtil(0, 0, 0, num); 
} 
int solve(){
    cin>>str>>K;
    vi v;
    rep(i,0,sz(str)-1){
        v.pb(str[i]-'0');
    }
    int t1=countInRange(v)-countIniRange(0);
    // ans=countInRange(v)-countIniRange(1);
    K=K-1;
    int t2=countInRange(v)-countIniRange(0);
    cout<<t1-t2;
    return 0;
}

signed main() {
    ios::sync_with_stdio(0);
    //std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
