//url:https://atcoder.jp/contests/abc054/tasks/abc054_c
//problem name:C - One-stroke Path

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void print_vec(vector<int> vec) {
    cout << "{";
    for(auto s: vec) cout << s << " ";
    cout << "}" << endl;
}

int main() {
    int N,M; cin >> N >> M;
    vector<vector<int>> G(N,vector<int>());
    vector<int> num(N);

    for(int i = 0; i < N; i++) num.at(i) = i; 

    rep(i,M) {
        int a,b;
        cin >> a >> b;
        G.at(a-1).push_back(b-1);
        G.at(b-1).push_back(a-1);
    }

    int ans = 0;

    do {
        if(num.at(0) != 0) break;
        //print_vec(num);
        bool ok = true;
        for(int i = 0; i < N-1;i++) {
            vector<int> g = G.at(num[i]);
            if(count(g.begin(),g.end(),num[i+1]) == 0) ok = false;
        }
        if(ok) ans++;
    } while(next_permutation(num.begin(),num.end()));

    cout << ans << endl;


}
