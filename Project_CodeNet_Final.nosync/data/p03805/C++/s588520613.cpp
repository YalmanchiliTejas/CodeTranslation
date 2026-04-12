#include<bits/stdc++.h>
using namespace std;

int main(){
    unsigned long N, M;
    cin >> N >> M;
    deque<deque<bool>> edges(N, deque<bool>(N, true));
    for(unsigned long i = 0, a, b; i < M; ++i){
        cin >> a >> b;
        --a;
        --b;
        edges[a][b] = edges[b][a] = false;
    }
    vector<unsigned long> v(N);
    iota(v.begin(), v.end(), 0);
    unsigned long ans{1};
    for(unsigned long i = 2; i < N; ++i)ans *= i;
    ++ans;
    do for(unsigned long i = 1; i < N; ++i)if(edges[v[i - 1]][v[i]] && --ans)break;
    while(next_permutation(v.begin() + 1, v.end()));
    cout << ans - 1 << endl;
    return 0;
}