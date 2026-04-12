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




int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(26, 0));

    rep(i, n){
        string s;
        cin >> s;

        for(char c : s){
            v[i][c - 'a']++;
        }
    }
    string res = "";
    vector<int> list(26, INF);
    rep(i, 26){
        rep(j, n){
            list[i] = min(list[i], v[j][i]);
        }
    }
    rep(i, 26){
      char c = 'a' + i;
        rep(j, list[i])res.push_back(c);
    }
    cout << res << endl;
}
