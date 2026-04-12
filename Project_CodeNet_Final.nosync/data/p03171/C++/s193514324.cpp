#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define fo(i,n) for(int i=0; i<n; i++)
#define Fo(i,k,n) for(int i=k; i<n; i++)
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

int N;
vl a;
vector<vector<pair<ll, ll>>> dp;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin>>N;
    a.resize(N);
    fo(i,N)cin>>a[i];
    dp.resize(N+1, vector<pair<ll, ll>>(N+1));
    fo(i,N){
        if((N-1)%2)dp[i+1][i+1] = make_pair(0, a[i]);
        else dp[i+1][i+1] = make_pair(a[i], 0);
    }
    Fo(len, 2, N+1){
        for(int l=1; l+len-1<=N; l++){
            int r=l+len-1;
            if((N-len)%2){
                dp[l][r] = (dp[l][r-1].second+a[r-1])>(dp[l+1][r].second+a[l-1]) ? make_pair(dp[l][r-1].first, dp[l][r-1].second+a[r-1]) : make_pair(dp[l+1][r].first, dp[l+1][r].second+a[l-1]);
            }else{
                dp[l][r] = (dp[l][r-1].first+a[r-1])>(dp[l+1][r].first+a[l-1]) ? make_pair(dp[l][r-1].first+a[r-1], dp[l][r-1].second) : make_pair(dp[l+1][r].first+a[l-1], dp[l+1][r].second);
            }
        }
    }
    cout<<dp[1][N].first-dp[1][N].second<<endl;
    
    return 0;
}