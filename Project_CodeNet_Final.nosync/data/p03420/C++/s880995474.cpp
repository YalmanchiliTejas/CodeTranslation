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
    #define rep(i,n)for(int i=0;(i)<(int)(n);i++)
    #define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
    #define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
    #define vec(type,n) vector<type>(n)
    #define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
    #define ALL(a)  (a).begin(),(a).end()
     
    using namespace std;
    using ll = long long;
    using Graph = vector<vector<int>>;
    using P = pair<int, int>;
     
const int MOD = 1e9 + 7;

int main(){
   ll n, k;
   cin >> n >> k;
   ll res = 0;
   if(k == 0){
      cout << n * n << endl;
      return 0;
   }
   REP(b, k + 1, n){
      //cout << (n / b) * (b - k) << " " <<  (n % b + 1 - k) << endl;
      res += (n / b) * (b - k);
      if((n % b + 1 - k) > 0)res += (n % b + 1 - k);
   }
   cout << res << endl;
}
