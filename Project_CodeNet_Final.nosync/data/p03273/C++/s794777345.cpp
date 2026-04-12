#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;

    vector<vector<char>> a(h, vector<char>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> a[i][j];
        }
    }

    vector<int> b(w,0);
    for(int j=0; j<w; j++){
        for(int i=0; i<h; i++){
            if(a[i][j] == '#'){
                b[j] = 1;
                break;
            }
        }
    }

    vector<int> c(h,0);
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(a[i][j] == '#'){
                c[i] = 1;
                break;
            }
        }
    }    
    for(int i=0; i<h; i++){
        if(c[i] == 0) continue;

        for(int j=0; j<w; j++){
            if(b[j] == 1) cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}