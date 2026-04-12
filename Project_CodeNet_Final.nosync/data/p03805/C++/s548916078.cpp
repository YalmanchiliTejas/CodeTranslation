#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N, M; cin >> N >> M;
    int Mat[N+1][N+1];
    memset(Mat, 0, sizeof(Mat));
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        Mat[a][b] = 1;
        Mat[b][a] = 1;
    }
    vector<int> v;
    for(int i = 1; i <= N; i++){
        v.push_back(i);
    }
    int cnt = 0;
    
    do {
        bool flag = true;
        if(v[0] != 1) continue;
        //for(auto x : v) cout << x << " "; cout << "\n";
        for(int i = 0; i < N-1; i++){
            int x = v[i];
            int y = v[i+1];
            //cout << Mat[x][y];
            if(Mat[x][y] != 1) flag = false;
        }
        //cout << endl;
        if(flag) {
            //cout << "y" << endl;
            cnt++;
        }
        //for(auto x : v) cout << x << " "; cout << "\n";
    } while( next_permutation(v.begin(), v.end()) );
    cout << cnt << endl;
    return 0;
}