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

int n, a[3005];

ll dp[2][3005][3005];
ll go2(int i, int j);
ll go1(int i, int j){
    //error(i,j);
    if(dp[0][i][j]!=-1){
        return dp[0][i][j];
    }
    if(i>j)
        return 0;
    return dp[0][i][j] = max(a[i]+go2(i+1,j),a[j]+go2(i,j-1));
}
ll go2(int i, int j){
    //error(i,j);
    if(dp[1][i][j]!=-1){
        return dp[1][i][j];
    }
    if(i>j)
        return 0;
    return dp[1][i][j] = min(go1(i+1,j)-a[i],go1(i,j-1)-a[j]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i = 0; i<n; ++i)
        cin>>a[i];
    cout<<go1(0,n-1)<<"\n";
    return 0;
}