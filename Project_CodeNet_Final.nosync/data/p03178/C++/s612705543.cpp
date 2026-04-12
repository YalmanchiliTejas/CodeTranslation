#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define MAX 100005
#define ff first
#define ss second
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int M = 1000000007;
string s;
int d;
int dp[105][10005][2];
void add_self(int &a, int b){
    a+=b;
    if(a>=M)
        a-=M;
}
int go(int idx, int less, int m){
    if(dp[m][idx][less]!=-1)
        return dp[m][idx][less];
    if(idx==s.size())
        return m==0;
    dp[m][idx][less]=0;
    int ds = s[idx]-'0';
    for(int i = 0; i<=9; ++i){
        if(i>ds&&(!less))
            break;
        int ii = i%d;
        int nxt_m = (m+ii)%d;
        add_self(dp[m][idx][less],go(idx+1,i<ds||less,nxt_m));
    }
    //error(idx,m,less,dp[m][idx][less]);
    return dp[m][idx][less];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s>>d;
    memset(dp,-1, sizeof(dp));
    int ans = go(0,0,0);
    ans-=1;
    if(ans==-1)
        ans = M-1;
    cout<<ans<<"\n";
    //error(dp[0][1]);    
}