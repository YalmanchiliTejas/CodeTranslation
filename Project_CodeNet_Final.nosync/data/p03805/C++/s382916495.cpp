#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> edge(n, vector<bool>(n, false));
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        edge[a - 1][b - 1] = edge[b - 1][a - 1] = true;
    }
    vector<int> move;
    for(int i = 1; i < n; i++){
        move.push_back(i);
    }
    int ans = 0;
    do{
        bool check = true;
        int now = 0;
        for(auto&& i : move){
            if(!edge[now][i]){
                check = false;
                break;
            }
            now = i;
        }
        ans += check;
    }while(next_permutation(begin(move), end(move)));
    cout << ans << "\n";
}