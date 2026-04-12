#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define fo(i,CApiTaL_N) for(int i=0; i<CApiTaL_N; i++)
#define Fo(i,k,CApiTaL_N) for(int i=k; i<CApiTaL_N; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for(auto it=a.begin(); it!=a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

int t;
const int mxN=3e3;
int n;
vl a(mxN+1);
vector<vector<vpll>> dp(mxN+1,vector<vpll>(mxN+1,vpll(4)));

void test_case(){
    cin>>n;
    Fo(i,1,n+1)cin>>a[i];
    Fo(i,1,n+1){
        dp[i][i][0]=mp(a[i],0);
        dp[i][i][1]=mp(0,a[i]);
    }
    Fo(len,2,n+1){
        Fo(srt,1,n+2-len){
            // cout<<srt<<" "<<len<<endl;
            dp[srt][srt+len-1][0]=max(mp(dp[srt+1][srt+len-1][1].first+a[srt],dp[srt+1][srt+len-1][1].second),mp(dp[srt][srt+len-2][1].first+a[srt+len-1],dp[srt][srt+len-2][1].second));
            if(a[srt]+dp[srt+1][srt+len-1][0].second > a[srt+len-1]+dp[srt][srt+len-2][0].second){
                dp[srt][srt+len-1][1]=mp(dp[srt+1][srt+len-1][0].first,a[srt]+dp[srt+1][srt+len-1][0].second);
            }else{
                dp[srt][srt+len-1][1]=mp(dp[srt][srt+len-2][0].first,a[srt+len-1]+dp[srt][srt+len-2][0].second);
            }
        }
    }
    cout<<dp[1][n][0].first-dp[1][n][0].second<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    t=1;
    while(t--){
        test_case();
    }
    
    return 0;
}