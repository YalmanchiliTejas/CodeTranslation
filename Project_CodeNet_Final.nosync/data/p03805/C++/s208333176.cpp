#include <bits/stdc++.h>
using namespace std;

int main(){
    int M,N;cin >> N >> M;
    int g[10][10] = {0};

    for(int i = 0 ; i < M ; i++){
        int a,b;cin >> a >> b;
        a--;b--;
        g[a][b] = g[b][a] = 1;
    }

    vector<int> v(N-1);
    for(int i = 1; i < N ; i++){
        v[i-1] = i;
    }
    int ans = 0;

    do{
        int nv = 0;
        for(int i = 0 ; i < v.size() ; i++){
            if(g[nv][v[i]] == 0)break;
            nv = v[i];
            if(i == v.size()-1)ans++;
        }
    }while(next_permutation(v.begin(),v.end()));

    cout << ans << endl;
}