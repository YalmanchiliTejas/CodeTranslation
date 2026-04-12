#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    vector<bool> row(h, false);
    vector<bool> col(w, false);
    for(int i = 0; i < h; i++){
        cin >> a[i];
        for(int j = 0; j < w; j++){
            if(a[i][j] == '#'){
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for(int i = 0; i < h; i++){
        if(row[i]){
            for(int j = 0; j < w; j++){
                if(col[j]){
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}