#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector> 
#include<limits>
#include<numeric>
#include<type_traits>
#include<math.h>
using namespace std;
typedef long long ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define in(x) cin >> x
#define out(str) cout << str << endl

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int N,M,a,b,ans;
bool g[8][8];

int main(){
    cin>>N>>M;
    vector<int> v;
    rep(i,N-1){
        v.push_back(i+1);
    }
    rep(i,8){
        rep(j,8){
            g[i][j]=0;
        }
    }
    rep(i,M){
        cin>>a>>b;
        a--;
        b--;
        g[a][b]=1;
        g[b][a]=1;
    }
    do{
        rep(i,N-1){
            if(!i){
                if(!g[0][v[0]])break;
            }
            else{
                if(!g[v[i-1]][v[i]])break;
            }
            if(i==N-2){
                ans++;
            }
        }

    }while(next_permutation(v.begin(),v.end()));
    out(ans);
}
