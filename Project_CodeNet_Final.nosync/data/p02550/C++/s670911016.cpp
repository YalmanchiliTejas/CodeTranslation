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
    #define pb push_back
     
    using namespace std;
    using ll = long long int;
    using Graph = vector<vector<int>>;
    using P = pair<ll, ll>;
     
const int MOD = 1e9 + 7;
const ll ZER = 0;


int main(){
    ll n, x, m;
    cin >> n >> x >> m;
    Graph G(m);
    ll tmp = x;
    ll cnt = 0;
    vector<ll> v;
    while(1){
        //cout << x << endl;
        G[x].push_back(x * x % m);
        if(G[x].size() == 2)break;
      	cnt++;
      	v.pb(x);
        x = x * x % m;
    }
    //cはしっぽの長さ,lはループの長さ
    ll c = 0, l;
    x = tmp;
    while(1){
        if(G[x].size() == 2)break;
        c++;
        x = x * x % m;
    }
    l = cnt - c;
    ll res = 0;
    x = tmp;
  	//rep(i, cnt)cout << v[i] << " ";
  	//cout << l << endl;return 0;
    if(n <= cnt){
        rep(i, n)res += v[i];
    }
    else {
        rep(i, cnt)res += v[i];
        n -= cnt;
      	//ループ何回するか
        REP(i, c, cnt - 1){
            res += (v[i] * (n / l));
        }
        n %= l;
        rep(i, n)res += v[c + i];
    }
    cout << res << endl;
}

