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
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)


using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

int N;
string s;

vector<int> solve(int z, int o){
    vector<int> rec(N+20, -1);
    rec[0] = z;
    rec[1] = o;
    if(rec[0] == 0){
        if(s[0] == 'o')rec[N+1] = rec[1];
        else rec[N+1] = 1 - rec[1];
    }
    else {
        if(s[0] == 'o')rec[N+1] = 1 - rec[1];
        else rec[N+1] = rec[1];
    }

    REP(i, 1, N-1){
        if(rec[i] == 0){
            if(s[i] == 'o')rec[i+1] = rec[i-1];
            else rec[i+1] = 1 - rec[i-1];
        }
        else {
            if(s[i] == 'o')rec[i+1] = 1 - rec[i-1];
            else rec[i+1] = rec[i-1];
        }
    }
    vector<int> FA(1, -1);
    if(rec[N-1] == rec[N+1] && rec[0] == rec[N])return rec;
    else return FA;
}

int main(){
    cin >> N >> s;
    rep(i, 2){
        rep(j, 2){
            vector<int> res(N+1, 0);
            res = solve(i, j);
            if(res[0] == -1)continue;
            else {
                rep(k, N){
                    if(res[k] == 0)cout << 'S';
                    else cout << 'W';
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}