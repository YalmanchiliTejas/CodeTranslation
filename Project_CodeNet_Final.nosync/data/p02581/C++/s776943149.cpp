#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int inf = 1<<30;
constexpr int mo = 1e9+7;
constexpr ll infl = 1ll<<60;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    vector<int> a(3*n);
    for(auto & b : a) cin>>b,b--;
    vector<vector<int>> dp(n,vector<int>(n,-(1<<20)));
    vector<int> ma(n,-(1<<20));
    dp[a[0]][a[1]] = 0;
    ma[a[0]] = ma[a[1]] = 0;
    int ret = 0;
    for(int i=2;i+2<3*n;i+=3){
        sort(a.begin()+i,a.begin()+i+3);
        if(a[i] == a[i+2]){
            ret++;
            continue;
        }
        
        vector<tuple<int,int,int>> co;
        if(a[i] == a[i+1]){
            for(int x=0;x<n;++x){
               co.emplace_back(x,a[i+2],max(dp[a[i]][x],dp[x][a[i]])+1); 
            }
        }
        if(a[i+1] == a[i+2]){
            for(int x=0;x<n;++x){
                co.emplace_back(x,a[i],max(dp[a[i+1]][x],dp[x][a[i+1]])+1);
            }
        }
                
        for(int j=i;j<i+3;++j){
            for(int x=0;x<n;++x)co.emplace_back(x,a[j],ma[x]);
        }
        
        co.emplace_back(a[i],a[i+1],dp[a[i+2]][a[i+2]]+1);
        co.emplace_back(a[i+1],a[i+2],dp[a[i]][a[i]]+1);
        co.emplace_back(a[i],a[i+2],dp[a[i+1]][a[i+1]]+1);

        
        int tmp = -1;
        for(int x=0;x<n;++x) tmp = max(tmp,ma[x]);
        co.emplace_back(a[i],a[i+1],tmp);
        co.emplace_back(a[i+1],a[i+2],tmp);
        co.emplace_back(a[i],a[i+2],tmp);
        
        for(auto  cur : co){
            int a,b,c;
            tie(a,b,c) = cur;
            dp[a][b] = max(dp[a][b],c);
            ma[a] = max(ma[a],c);
            ma[b] = max(ma[b],c);
        }
    }
    
    int sma = 0;
    for(int i=0;i<n;++i) sma = max(sma,ma[i]);
    sma = max(sma,dp[a[3*n-1]][a[3*n-1]] + 1);
    cout << ret+sma << endl;
    return 0;
}