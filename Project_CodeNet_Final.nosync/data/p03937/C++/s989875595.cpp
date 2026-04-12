#include <iostream>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

int main(){
    int h, w, prev_l = 0, prev_r = 0;
    cin >> h >> w;
    string line;
    bool flag = true;
    rep(i, h){
        int l = w, r = -1;
        cin >> line;
        rep(j, w){
            if(line[j] == '#'){
                l = min(l, j);
                r = max(r, j);
            }
        }
        if(prev_r != l){
            flag = false;
        }
        prev_l = l, prev_r = r;
    }
    printf(flag ? "Possible\n" : "Impossible\n");
}