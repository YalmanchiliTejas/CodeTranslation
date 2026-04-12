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

ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}

const int mod = INF+7;
int main(){
    int a,b,c,x,y;cin>>a>>b>>c>>x>>y;
    int res = 0;
    if(a+b<=2*c){
        res = a*x+b*y;
    }
    else {
        res += 2*c*min(x,y);
        int mn = min(x,y);
        x -= mn,y -= mn;
        if(a*x+b*y>2*c*max(x,y))res += 2*c*max(x,y);
        else res += a*x+b*y;
    }
    cout<<res<<endl;
}

