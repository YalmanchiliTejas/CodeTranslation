#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;


Int all(Int n){//no bb
    Int rr = 1, bb = 1, rb = 0, br = 0;
    for(int i = 1;i < n;i++){
        Int nrr = (rr+rb) % MOD;
        Int nbb = br;
        Int nrb = rr;
        Int nbr = (bb + br) % MOD;
        rr = nrr;
        bb = nbb;
        rb = nrb;
        br = nbr;
    }
    return (rr + rb + br) % MOD;
}

Int tmp[216000];
Int rdp[216000];
Int dp[216000];
void calc(Int n, Int limit){
    dp[0] = 1;
    rdp[0] = 1;
    for(int i = 1;i <= n+1;i++){
        dp[i] = (rdp[i-1] - ((i-limit-1)>=0?rdp[i-limit-1]:0)) % MOD;
        if(dp[i] < 0)dp[i] += MOD;
        rdp[i] = (rdp[i-1] + dp[i]) % MOD;
    }
}

Int solve(Int n, Int limit){
    if(n % 2 == 1)return 0;
    limit = (limit+1) / 2;
    n /= 2;
    Int res = 0;
    calc(n+10, limit);
    for(Int i = 1;i <= limit;i++){
        if(n-i >= 0)res = (res + dp[n-i]*2*i) % MOD;
    }
    return res % MOD;
}

int main(){
    Int n, m;
    string str;
    vector<Int> vec;
    cin >> n >> m;
    cin >> str;
    bool allsame = true;
    for(int i = 0;i < m;i++)allsame &= (str[i] == str[0]);
    if(allsame){
        cout << all(n) << endl;
        return 0;
    }
    for(int i = 0;i < m;i++)vec.push_back(str[i] == str[0]);
    Int l = 0;
    while(vec[l] == 1)l++;
    if(l % 2 == 0)l++;
    Int limit = l;
    l = 0;
    for(int i = 0;i < vec.size();i++){
        if(vec[i] == 1)l++;
        else{
            if(l % 2 == 1)limit = min(limit, l);
            l = 0;
        }
    }
    cout << solve(n, limit) << endl;
    return 0;
}