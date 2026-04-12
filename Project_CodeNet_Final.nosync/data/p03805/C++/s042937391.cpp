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
    #define chmin(a, b) a = min(a, b)
    #define chmax(a, b) a = max(a, b)
     
    using namespace std;
    using ll = long long;
    using Graph = vector<vector<int>>;
    using P = pair<ll, ll>;
    using T = ll;
     
const int MOD = 1e9 + 7;


int main(){
   int n, m;
   cin >> n >> m;
   Graph G(n);
   rep(i, m){
      int a, b;
      cin >> a >> b;
      a--;b--;
      G[a].push_back(b);
      G[b].push_back(a);
   }
   vector<int> al(n);
   rep(i, n)al[i] = i;
   int res = 0;
   do{
      if(al[0] != 0)continue;

     
      bool f = true;
      rep(i, n - 1){
         int v = al[i];
         bool g = false;
         for(int nv : G[v]){
            if(nv == al[i + 1])g = true;
         }
         if(!g)f = false;
      }
      if(f)res++;
   }while(next_permutation(ALL(al)));
   cout << res << endl;
}
