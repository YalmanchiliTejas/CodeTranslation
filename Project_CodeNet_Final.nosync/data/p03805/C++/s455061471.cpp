#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define ll long long
#define vi vector<int>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int N, M, a, b, cnt = 0;
vi T[13], vec;

bool CheckPath(int u, int v){
    rep(i,T[u].size())
        if(T[u][i] == v) return true;
    return false;
}

void solve(){
    vec.resize(N-1);
    rep(i,N-1) vec[i] = i+1;

    do{
        int prev = 0; cnt++;

        rep(i,N-1){
            int id = vec[i];
            if(!CheckPath(prev,id)){
                // printf("No Path from %d to %d\n", prev, id);
                cnt--;
                break;
            }
            // printf("Path from %d to %d exists\n", prev, id);
            prev = id;
        } 
        // printf("Count:%d\n",cnt);
    }while(next_permutation(vec.begin(), vec.end()));

    cout << cnt << endl;
}

int main(){
    cin >> N >> M;

    rep(i, M){
        cin >> a >> b; a--; b--; //0-indexに
        T[a].push_back(b); T[b].push_back(a);
    } 
    solve();
}
