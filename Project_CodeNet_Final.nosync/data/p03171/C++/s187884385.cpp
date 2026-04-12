#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(i, a, b) for(int i=a; i<b; i++)
typedef long long ll;
typedef vector<int> vi;

vector<vector<pair<ll, bool>>> dp[2];
int *a;

ll find2(int, int);

ll find1(int l, int r){
    if(l==r){
        return a[l];
    }
    if(dp[0][r][l].second){
        return dp[0][r][l].first;
    }
    ll x1=a[l]+find2(l+1, r);
    ll x2=a[r]+find2(l, r-1);
    dp[0][r][l]={max(x1, x2), 1};
    return dp[0][r][l].first;
}

ll find2(int l, int r){
    if(l==r){
        return -1*a[l];
    }
    if(dp[1][r][l].second){
        return dp[1][r][l].first;
    }
    ll x1=find1(l+1, r)-a[l];
    ll x2=find1(l, r-1)-a[r];
    dp[1][r][l]={min(x1, x2), 1};
    return dp[1][r][l].first;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    a=new int[n];
    dp[0].resize(n);
    dp[1].resize(n);
    FOR(i, 0, n){
        cin>>a[i];
        dp[0][i].resize(i+1, {0, 0});
        dp[1][i].resize(i+1, {0, 0});
    }
    cout<<find1(0, n-1)<<endl;
    return 0;
}