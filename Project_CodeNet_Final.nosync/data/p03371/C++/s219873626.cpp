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

    #define INF 1e7
    #define rep(i,n)for(int i=0;(i)<(int)(n);i++)
    #define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
    #define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
    #define vec(type,n) vector<type>(n)
    #define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))

    using namespace std;
    using ll = long long;
    using Graph = vector<vector<int>>;
    using P = pair<int,int>;

    int main(){
        int a,b,c,x,y;cin>>a>>b>>c>>x>>y;
        int res = 0;
        int mn = min(x,y);
        res = min(a+b,2*c)*mn;
        x-=mn;y-=mn;
        if(x)res += min(a*x,2*c*x);
        if(y)res += min(b*y,2*c*y);
        cout<<res;
    }
    
