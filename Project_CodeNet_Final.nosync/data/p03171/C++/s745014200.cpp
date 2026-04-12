#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long
#define pi pair<int,int>
#define pl pair<ll,ll>
#define pd pair<double,double>
#define ld long double
#define pld pair<ld,ld>
#define lg length()
#define sz size()
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pi>
#define vpl vector<pl>
#define pb push_back
#define INF 1000000005
#define LINF 1000000000000000005
using namespace std;
ll dp[3005][3005];
int v[3005][3005];
int a[3005];
int n;
ll rec(int l , int r){
    if(v[l][r] == 1)return dp[l][r];
    v[l][r] = 1;
    if(l == r){dp[l][r] = a[l];}
    else{dp[l][r] = max(a[l] - rec(l+1,r) , a[r] - rec(l,r-1));}
    return dp[l][r];
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    for(int i = 1 ; i <=n; i++){
        cin >> a[i];
    }
    cout << rec(1,n) << endl;

}
