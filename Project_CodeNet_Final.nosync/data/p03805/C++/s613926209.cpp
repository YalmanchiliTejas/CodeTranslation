#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

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
    vector<int> junretsu;
    rep(i,N-1){
        junretsu.push_back(i+2);
    }
    int cnt=0;
    do{
        bool fl = false;
        int tmp = 1;
        rep(i,N-1){
            if(hen.at(tmp).count(junretsu.at(i))){
                tmp = junretsu.at(i);
            }else{
                fl = true;
                break;
            }
        }
        if(fl) continue;
        cnt++;
    }while( next_permutation(junretsu.begin(),junretsu.end()) );
    cout << cnt << endl;
}   