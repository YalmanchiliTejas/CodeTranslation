#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

vector<bool> solve(int n, vector<bool> const & s){
    rep(i,2){
        rep(j,2){
            vector<bool> res(n);
            res.at(0) = i;
            res.at(1) = j;
            for(int k = 2; k < n; k++){
                res.at(k) = res.at(k-1)^res.at(k-2)^s.at(k-1);
            }
            if(s.at(n-1)==res.at(n-2)^res.at(n-1)^res.at(0)&&s.at(0)==res.at(n-1)^res.at(0)^res.at(1))return res;
        }
    }
    return vector<bool>();
}

int main(){
    int N; cin>>N;
    vector<bool> S(N);
    rep(i,N){
        char tmp; cin>>tmp;
        S.at(i) = (tmp=='o');
    }
    vector<bool> res = solve(N,S);
    if(res.empty())cout<<-1<<endl;
    else{
        for(auto b: res) cout << (b ? 'S' : 'W');
        cout << endl;
    }
    return 0;
}