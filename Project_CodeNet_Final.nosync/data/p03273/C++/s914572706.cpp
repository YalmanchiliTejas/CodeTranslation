#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 2000000000;//10^9
ll MOD  = 998244353;

int main() {
    int H,W;
    cin >> H >> W;
    char a[H][W];
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> a[i][j];
        }
    }
    
    vector<int> h(0);
    vector<int> w(0);
    for(int i = 0; i < H; i++){
        bool l = false;
        for(int j = 0; j < W; j++){
            if(a[i][j] == '#'){
                l = true;
            }
        }
        if(l)h.push_back(i);
    }
    for(int j = 0; j < W; j++){
        bool l = false;
        for(int i = 0; i < H; i++){
            if(a[i][j] == '#'){
                l = true;
            }
        }
        if(l)w.push_back(j);
    }
    for(int x : h){
        for(int y : w){
            cout << a[x][y];
        }
        cout << endl;
    }
    
    
}