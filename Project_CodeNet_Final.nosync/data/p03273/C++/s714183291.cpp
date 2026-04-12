#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector< string > mp;
typedef vector<bool > vi;

int main(){
    int H,W;
    cin >> H >> W;
    mp dp(H);
    vi row(H, false);
    vi col(W, false);
    for(int i = 0; i < H; i++){
        cin >> dp[i];
        for(int j=0; j < W; j++){
            if( dp[i][j] == '#'){
                row[i] = true;
                col[j] = true;
            }
        }
    }
    // cout <<'a';
    for(int i = 0; i < H; i++){
        if(row[i]){
            for(int j=0; j < W; j++){
                if(col[j]){
                    cout <<  dp[i][j];
                }
            }
            cout << endl;
        }
    }
}