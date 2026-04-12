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
    vector<ll> id(m, -1);
    vector<ll> a;
    ll len = 0;
    ll tot = 0;
    while(id[x] == -1){
        a.push_back(x);
        id[x] = len;
        len++;
        //トータルの和
        tot += x;
        x = x * x % m;
    }

    ll c = len - id[x];
    //周期の中の和
    ll s = 0;
    REP(i, id[x], len - 1)s += a[i];
    ll res = 0;
    if(n <= len){
        rep(i, n)res += a[i];
    }
    else {
        res += tot;
        n -= len;
        res += s * (n / c);
        n %= c;
        rep(i, n)res += a[id[x] + i];
    }
    cout << res << endl;
}

