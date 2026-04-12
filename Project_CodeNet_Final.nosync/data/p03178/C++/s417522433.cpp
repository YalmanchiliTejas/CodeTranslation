#include<bits/stdc++.h>
#define all(x) x.begin() , x.end()
#define ll long long 
#define pb push_back
#define mp make_pair

using namespace std;
const int mx = 10001;
long long dp[mx][100][2] , d;
bool visited[mx][100][2];
string n;
long long MOD = 1e9 + 7;
long long dfs(int pos , int sum , bool less){
    if(pos >= n.size())return !sum;
    if(visited[pos][sum][less])return (dp[pos][sum][less])%MOD;
    visited[pos][sum][less] = 1;
    long long ans = 0;
    for(int i = 0; i < 10; ++i){
        if(less || i <= n[pos] - '0'){
            ans += dfs(pos + 1 , (sum + i)%d , less || i < n[pos] - '0') % MOD;
        }
    }
    return dp[pos][sum][less] = ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>d;
    cout<<(dfs(0 , 0 , 0) - 1) % MOD<<endl;

}