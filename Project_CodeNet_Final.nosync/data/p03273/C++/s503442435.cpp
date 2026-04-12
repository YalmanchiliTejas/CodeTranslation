#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static const int MAX = 100;
bool mat[MAX][MAX];
int col[MAX], row[MAX];

int main(){
    int h, w;
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            char c;
            cin >> c;
            mat[i][j] = (c == '#');
            if(c == '#'){
                row[i]++;
                col[j]++;
            }
        }
    }
    for(int i = 0; i < h; i++){
        if(!row[i]) continue;
        for(int j = 0; j < w; j++){
            if(!col[j]) continue;
            cout << (mat[i][j] ? '#' : '.');
        }
        cout << endl;
    }
    return 0;
}