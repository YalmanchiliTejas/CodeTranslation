#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include <cassert>
#include <cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()


using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

string s;
int k;

//桁dp
ll dp[105][2][4];
ll solve(string s){
    //fill(dp,(ll)0);
    dp[0][0][0] = 1;
    //string s = to_string(n);
    rep(i,s.size()){            //各桁について調べる
        const int D = s[i]-'0';
        rep(j,2){               //その桁がもとの数字の桁の数と一致してるかどうか
            rep(k,4){           //そのdpが4か9をもつかどうか
                rep(d,(j?10:D+1)){
                    if(d == 0)dp[i + 1][j || (d < D)][k] += dp[i][j][k];
                    if(k == 3)continue;
                    if(d != 0)dp[i + 1][j || (d < D)][k + 1] += dp[i][j][k];
                }
            }
        }
    }
    return dp[s.size()][0][k] + dp[s.size()][1][k];
}

int main(){
    cin >> s >> k;
    ll res = solve(s);
    cout << res << endl;
}
