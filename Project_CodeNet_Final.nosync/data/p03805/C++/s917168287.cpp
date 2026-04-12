#include <bits/stdc++.h>
#define rep(i, n)  for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int N,M; cin >> N >> M;
    vector<int> nodes(N);
    rep(i,N) nodes[i] = i+1;

    vector<P> vec(M);
    rep(i,M){
        int a,b; cin >> a >> b;
        vec[i] = P(a,b);
    }
    int ans = 0;    
    do{
        bool ok = true;
        rep(i, N-1){
            bool exists = false;
            rep(j, M){
                if(vec[j] == P(nodes[i], nodes[i+1]) || vec[j] == P(nodes[i+1], nodes[i])){
                    exists = true;
                }
            }
            if(!exists) ok = false;
        }
        if(ok) ++ans;
    }while(next_permutation(nodes.begin() + 1, nodes.end()));
    cout << ans << endl;
}