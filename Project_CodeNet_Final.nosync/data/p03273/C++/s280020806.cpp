#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = -0; i < H; i++) {
        cin >> S[i];
    }
    vector<bool> tate(W, false);
    vector<bool> yoko(H, false);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if(S[i][j] == '#'){
                yoko[i] = true;
                tate[j] = true;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if(yoko[i] == true && tate[j] == true){
                printf("%c", S[i][j]);
            }
        }
        if(yoko[i] == true){
            printf("\n");
        }
    }

}