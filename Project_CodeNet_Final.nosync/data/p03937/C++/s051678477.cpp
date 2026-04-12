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

int GCD(int a,int b){
    if(b==0)return a;
    return GCD(b,a%b);
}

int main(){
    int h,w;cin>>h>>w;
    vector<string>s(h);
    bool f[h][w];
    rep(i,h)rep(j,w)f[i][j] = false;
    rep(i,h)cin>>s[i];
    int dx[2] = {0,1};
    int dy[2] = {1,0};
    queue<P>que;
    que.emplace(0,0);

    while(!que.empty()){
        int y = que.front().first,x = que.front().second;
        f[y][x] = true;
        if(x==w-1 && y==h-1)break;
        que.pop();
        int cnt = 0;
        int nx,ny;
        rep(i,2){
            int xx = x+dx[i],yy = y+dy[i];
            if(xx<0 || xx>=w || yy<0 || yy>=h)continue;
            if(s[yy][xx]!='#')continue;
            ny = yy,nx = xx;
            cnt++;
        }
        if(cnt!=1){
            cout<<"Impossible"<<endl;
            return 0;
        }
        else que.emplace(ny,nx);
    }
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='#' && !f[i][j]){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    cout<<"Possible"<<endl;
}

