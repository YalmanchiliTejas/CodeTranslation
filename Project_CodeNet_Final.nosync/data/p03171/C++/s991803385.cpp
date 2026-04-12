#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pi pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pair<int,int> >
#define vll vector<pair<int,int> >
#define pb push_back
#define mp make_pair
#define qi queue<int>

const ll mod=1e9+7;
#define MAX 100000

template<typename T> void max_self(T &x,T y) { x = max(x,y); }
template<typename T> void min_self(T &x,T y) { x = min(x,y); }

ll solve(ll a,ll b,ll c){

    if(b==0) return 1;
    else if(b%2==0) return solve(((a%c)*(a%c))%c,b/2,c)%c;
    else return ((a%c)*(solve(((a%c)*(a%c))%c,b/2,c)%c))%c;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    int arr[n];
    FOR(i,0,n) cin>>arr[i];

    ll dp[n][n];

    for(int l = n-1;l>=0;l--){
        for(int r = l;r<n;r++){
            if(l == r) dp[l][r] = arr[l];
            else dp[l][r] = max(arr[l] - dp[l+1][r], arr[r] - dp[l][r-1]);
        }
    }

    cout<<dp[0][n-1];
    return 0;
}
