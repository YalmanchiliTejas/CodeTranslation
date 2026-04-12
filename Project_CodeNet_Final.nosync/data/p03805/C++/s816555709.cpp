#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check_edge(vector<int> vv, int i, vector<int> e) {
    if(min(vv[i], vv[i+1])==e[0] && max(vv[i], vv[i+1])==e[1]) return true;
    else return false;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int> > edge(M, vector<int>(2));
    for(int i=0; i<M; i++) {
        for(int j=0; j<2; j++) {
            cin >> edge[i][j];
        }
    }
    
    vector<int> v(N);
    
    for(int i=0; i<N; i++) {
        v[i] = i+1;
    }

    int ans=0;
    bool flag;

    do {
        if(v[0]!=1) continue;
        for(int j=0; j<N-1; j++) {
            flag=false;
            for(int k=0; k<M; k++) {
                if(check_edge(v, j, edge[k])) {
                    flag=true;
                    break;
                }
            }
            if(flag) continue;
            else break;
        }
        
        if(flag) ans++;

        // for(int i=0; i<N; i++) {
        //     cout << v[i] << " ";
        // }
        // cout << endl;

        
        
    } while(next_permutation(v.begin(), v.end()));

    cout << ans << endl;

    return 0;
    
}