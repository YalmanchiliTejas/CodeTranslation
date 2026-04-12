#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int N, M;
bool graph[10][10]; // i から j への有向線があるかどうか

int main() {
    // 初期化
    for (int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            graph[i][j] = false;
        }
    }

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = graph[b][a] = true;
    }

    vector<int> v(N);
    iota(v.begin(), v.end(), 1); // v = {1,2, ..., N}
    int res = 0;

    // 1, {2, 3, ..., N} の順列
    do {
        int len = v.size();
        for ( int i = 0; i < len-1; i++ ) {
            if( not graph[ v.at(i) ][ v.at(i+1) ] )
                break;

            if(i == len-2) // 道があった
                res++;
        }
    } while( next_permutation( v.begin()+1, v.end()) );

    cout << res << endl;
}