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


int main(){
    int n;cin>>n;
    vector<vector<int>>v(n,vector<int>(26));
    rep(i,n)rep(j,26)v[i][j] = 0;
    rep(i,n){
        string s;cin>>s;
        rep(j,s.size()){
            v[i][s[j]-'a']++;
        }
    }
    vector<int>vv(26,INF);
    rep(i,n){
        rep(j,26)vv[j] = min(v[i][j],vv[j]);
    }
    rep(i,26){
        if(vv[i]==0)continue;
        while(vv[i]--)cout<<(char)('a'+i);
    }
}

