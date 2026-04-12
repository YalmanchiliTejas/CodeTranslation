#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(void){
    int n,m;
    cin >> n >> m;
    vector<string> M = vector<string>(n);
    for(int i = 0; i < n; i++){
        cin >> M[i];
    }

    vector<int> rows = vector<int>(n, 0);
    vector<int> cols = vector<int>(m, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(M[i][j] == '#'){
                rows[i] = 1;
                break;
            }
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(M[j][i] == '#'){
                cols[i] = 1;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(rows[i]){
            for(int j = 0; j < m; j++){
                if(cols[j]) cout << M[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
