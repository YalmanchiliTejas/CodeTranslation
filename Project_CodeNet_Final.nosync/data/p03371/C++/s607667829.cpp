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
#include<cassert>
#include<cmath>
#include<cstdint>

#define INF 1e9
#define LINF 1e19
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
     
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;
     
const ll MOD = 1e9 + 7;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ch = 0, m;
    if(x > y){
      ch = 0;
      m  = y;
    }
    else {
      ch = 1;
      m = x;
    }
    ll res = 0;
    res = min((a + b) * m, 2 * c * m);
    if(ch == 0){
      m = x - m;
      res += min(a * m, 2 * c * m);
    }
    else {
      m = y - m;
      res += min(b * m, 2 * c * m);
    }
    cout << res << endl;
}



