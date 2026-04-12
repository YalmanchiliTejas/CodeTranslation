#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;

using Graph = vector<vector<int>>;

int main() {
    int N, M; cin >> N >> M;
    Graph G(N+1);
    for(int i=1; i<M+1; i++){
        int a, b;
        cin >> a >> b;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    vector<int> v(N+1,0);
    for(int i=0; i<N; i++){
        v.at(i) = i+1;
    }

    int cnt = 0;
    bool nextfg = false;
    do{
        int tmp = 0;
        if(v.at(0) != 1) break;
        for(int i=0; i<N; i++){
            for(int j=0; j<G.at(v.at(i)).size(); j++){
                if(G.at(v.at(i)).at(j) == v.at(i+1)){
                    tmp++;
                    break;
                }
                else if(j == G.at(v.at(i)).size() - 1){
                    nextfg = true;
                }
            }
            if(nextfg){
                nextfg = false;
                break;
            }
        }

        if(tmp == N-1) cnt++;
    }while(next_permutation(v.begin(),v.end())); // Please sort vector.

    cout << cnt << endl;
}