#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int pass_cnt(vector<set<int>> &hen,int N,vector<bool> checked,int tmp,int cnt){
    if(checked.at(tmp)) return 0;

    if(cnt == N) return 1;

    checked.at(tmp) = true;
    cnt++;
    int res =0;
    for(int next:hen.at(tmp)){
        res += pass_cnt(hen,N,checked,next,cnt);
    }
    return res;
}

int solve(vector<set<int>> &hen,int N){
    vector<bool> checked(N+1,0);

    return pass_cnt(hen,N,checked,1,1);
}

int main(){
    int N,M;
    cin >> N >> M;
    vector<set<int>> hen(N+1);
    int a,b;
    rep(i,M){
        cin >> a >> b;
        hen.at(a).insert(b);
        hen.at(b).insert(a);
    }
    cout << solve(hen,N) << endl;
}   