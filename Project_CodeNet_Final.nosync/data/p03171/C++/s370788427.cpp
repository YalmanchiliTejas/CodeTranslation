#include <bits/stdc++.h>
using namespace std;
void program(); int main() {cin.sync_with_stdio(0); cin.tie(0); cin.exceptions(cin.failbit); program();}
#define int long long
#define endl "\n"
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int,int>

#define N 3000
int n;
int a[N], dp[N][N];
int v(int, int);

int u(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];
    if(i == j){
        return a[i];
    }
    return dp[i][j] = max(a[i]+v(i+1,j),a[j]+v(i,j-1));
}

int v(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];
    if(i == j){
        return -a[i];
    }
    return dp[i][j] = min(-a[i]+u(i+1,j),-a[j]+u(i,j-1));
}

void program(){
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) dp[i][j] = -1;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<u(0,n-1)<<endl;
}

/*
WA:
-bounds on loops
-truncating
-intialization
-0 vs 1 indexing

TLE:
-might need unordered_set/map
-infinite while loop

Stuck:
-different perspective?
-bruteforce?
-greedy?
-reduce dimensionality with problem contraints?
*/
