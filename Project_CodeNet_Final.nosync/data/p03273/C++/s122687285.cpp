#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

int main(){
    vector <int> col;
    queue <int> row;
    int n, m;
    cin >> n >> m;
    
    char a[110][110];
    for(int i = 0; i < n; i++){
        bool ok = true;
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == '#') ok = false;
        }
        if(ok) row.push(i);
    }
    for(int i = 0; i < m; i++){
        bool ok = true;
        for(int j = 0; j < n; j++){
            if(a[j][i] == '#') ok = false;
        }
        if(ok) col.push_back(i);
    }
    
    
    for(int i = 0; i < n; i++){
        if(!row.empty()){
            if(i == row.front()){
                row.pop();
                continue;
            }
        }
        for(int j = 0; j < m; j++){
            bool ok = true;
            for(auto &k : col){
                if(k == j){
                    ok = false;
                    break;
                }
            }
            if(ok)cout << a[i][j];
        }
        cout << endl;
    }
}
