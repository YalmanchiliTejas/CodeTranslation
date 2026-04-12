#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;

int main(){    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> a;
    a = vector<vector<int>>(N, vector<int>(N,0));
    for(int i=0; i<M; i++){
        int s, g;
        cin >> s >> g;
        s--;  g--;
        a[s][g] = 1;  a[g][s] = 1;
    }

    vector<int> path;
    int ans = 0;
    for(int i=1; i<N; i++) path.push_back(i);
    do{
        int now = 0;
        for(int i=0; i<N-1; i++){
            int next = path[i];
            if(a[now][next]!=1) break;
            if(i==N-2) ans++;
            now = next;
        }
    } while(next_permutation(path.begin(), path.end()));

    cout << ans << endl;
}
