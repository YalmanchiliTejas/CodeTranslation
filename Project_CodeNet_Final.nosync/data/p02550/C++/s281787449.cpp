#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

template<typename T>
using vec2 = vector<vector<T>>;
template<typename T>
using vec3 = vec2<vector<T>>;
template<typename T>
using vec4 = vec3<vector<T>>;
template<typename T>
using vec5 = vec4<vector<T>>;
template<typename T>
using vec6 = vec5<vector<T>>;



int main(){
    ll N,X,M;
    cin>>N>>X>>M;
    vector<ll> route;
    vector<bool> visited(M, false);
    int loopstart = M+10;
    for(int i = 0;i < N;i++){
        if(visited[X]){
            loopstart = X;
            break;
        }
        visited[X]=true;
        route.push_back(X);
        X = (X*X)%M;
    }
    for(int i = 0;i < route.size();i++){
        if(route[i] == loopstart)loopstart = i;
    }
    // for(int i = 0;i < route.size();i++){
    //     cout<<route[i]<<" ";
    // }cout<<endl;
    // cout<<route.size()<<endl;
    // cout<<loopstart<<endl;
    ll res = 0;
    int K = route.size();
    N--;
    for(int i = 0;i < route.size();i++){
        if(i < loopstart){
            res += route[i];
            N--;
            continue;
        }
        int looplength = K - loopstart;
        int j = i - loopstart;
        res += route[i] * (N/looplength) + (j <= N % looplength ? route[i] : 0);
    // cout<<looplength<<" "<<j<<" "<<route[i] * (N/looplength) + (j <= N % looplength ? route[i] : 0)<<endl;
    }
    cout<<res<<endl;
}