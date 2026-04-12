#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;

int main(){
    int H, W; cin >> H >> W;
    vector<string> S;
    for(int i = 0; i < H; i++) {
        string tmp; cin >> tmp; 
        if( find(tmp.begin(), tmp.end(), '#') == tmp.end()) continue;
        else S.push_back(tmp);
    }
    H = S.size();
    vector<int> B(W);
    for(int j = 0; j < W; j++){
        bool f = true;
        for(int i = 0; i < H; i++){
            if(S[i][j] == '#') f = false;
        }
        if(f) B[j] = 1;
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(B[j] == 1) continue;
            else cout << S[i][j];
        }
        cout << endl;
    }

}