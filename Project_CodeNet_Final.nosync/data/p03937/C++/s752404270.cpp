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
    vector<int>S,False(1,-1);
    rep(i,n)if(bit&(1<<i))S.push_back(i);
    return S;
}

template<typename A,size_t N,typename T>
void Fill(A(&array)[N],const T &val){
    fill((T*)array,(T*)(array+N),val);
}

const ll INF = 1e10;
int main(){
    int h, w;
    cin >> h >> w;
    vector<string>field(h);
    rep(i, h)cin >> field[i];
    vector<bool> fh(h, false), fw(w, false);
    int cnt = 0;
    rep(i, h){
        rep(j, w){
            if(field[i][j] == '#'){
                fh[i] = true;
                fw[j] = true;
                cnt++;
            }
        }
    }
    bool alh = true, alw = true;
    rep(i, h)if(!fh[i])alh = false;
    rep(j, w)if(!fw[j])alw = false;
    cout << (alh && alw && cnt == h + w - 1 ? "Possible" : "Impossible") << endl;
}