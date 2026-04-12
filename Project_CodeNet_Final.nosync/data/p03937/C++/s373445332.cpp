#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    char c;
    int row = 0, col = 0;
    int all = 1, cnt = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> c;
            if (i==0 && j==0 && c=='.'){
                cout << "Impossible";
                return 0;
            }
            if (c == '.') 
                continue;
            cnt++;
            if (row == i && col == (j-1)){
                col++;
                all++;
                continue;
            }
            if (row == (i-1) && col == j){
                row++;
                all++;
            }
        }
    }
    if (row == (n-1) && col == (m-1) && all == cnt){
        cout << "Possible";
    }
    else {
        cout << "Impossible";
    }

    return 0; 
}
