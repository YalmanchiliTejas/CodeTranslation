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
using P = pair<int,int>;

vector<int>bitSearch(int bit,int n){
    vector<int>S;
    rep(i,n)if(bit&(1<<i))S.push_back(i);
    return S;
}


int d[3] = {-1,0,1};
int main(){
    int h,w;cin>>h>>w;
    vector<string>s(h);
    rep(i,h)cin>>s[i];
    vector<bool>f(h);
    vector<bool>g(w);
    rep(i,h){
        rep(j,w){
            if(s[i][j]!='.')break;
            if(j==w-1){
                f[i] = true;
            }
        }
    }
    rep(i,w){
        rep(j,h){
            if(s[j][i]!='.')break;
            if(j==h-1){
                g[i] = true;
            }
        }
    }
    rep(i,h){
        if(f[i])continue;
        rep(j,w){
            if(g[j])continue;
            cout<<s[i][j];
        }
        cout<<endl;
    }
}

