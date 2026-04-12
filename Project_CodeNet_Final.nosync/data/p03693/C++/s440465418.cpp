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

    using namespace std;
    using ll = long long;
    using Graph = vector<vector<int>>;
    using P = pair<int,int>;

    ll cmb(ll n,int a,int mod){
        ll res = 1;
        rep(i,a){
            res *= (n-i);
            res /= (i+1);
            res %= mod;
        }
        return res;
    }

    ll mod_pow(ll x,ll n,ll mod){
        ll res = 1;
        while(n>0){
            if(n&1)res = res*x%mod;
            x = x*x%mod;
            n >>= 1;
        }
        return res;
    }

    int main(){
      int r,g,b;cin>>r>>g>>b;
      int res = 100*r+10*g+b;
      cout<<(res%4==0 ? "YES":"NO");
    }
    
