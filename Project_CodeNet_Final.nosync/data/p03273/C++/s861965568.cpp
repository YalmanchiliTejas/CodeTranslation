#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<bool> skipRow(n, true), skipColumn(m, true);
    vector<string> vs(n);
    for(int i = 0; i < n; i++){
        cin >> vs[i];
        for(int j = 0; j < m; j++){
            if(vs[i][j] == '#'){
                skipRow[i] = skipColumn[j] = false;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(skipRow[i]) continue;
        for(int j = 0; j < m; j++){
            if(skipColumn[j]) continue;
            cout << vs[i][j];
        }
        cout << "\n";
    }
}