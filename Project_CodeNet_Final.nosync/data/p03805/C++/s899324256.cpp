#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using vvs = vector<vs>;
const ll MOD = 1e9+7;
const vi d8x = {1, 0, -1, 0, 1, -1, -1, 1};
const vi d8y = {0, 1, 0, -1, 1, 1, -1, -1};
const vi d4x = {1, 0, -1, 0};
const vi d4y = {0, 1, 0, -1};

int main(){
    int N,M; cin>>N>>M;
    vvi graph(M,vi(2));
    rep(i,M){
        rep(j,2){
            cin>>graph[i][j];
        }
    }
    
    vi vec(N);
    rep(i,N){
        vec[i]=i+1;
    }

    int ans =0;
    do{
        int ok =0;
        rep(i,N-1){
            rep(j,M){
                if((vec[i]==graph[j][0] && vec[i+1]==graph[j][1])|| (vec[i]==graph[j][1] && vec[i+1]==graph[j][0])) ok++;
            }
        }
        if(ok==N-1) ans++;

    } while(next_permutation(vec.begin() +1, vec.end()));

    cout<<ans<<endl;
}