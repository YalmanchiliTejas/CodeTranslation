#include <iostream>
using namespace std;

int main(){
    int H,W = 0;
    cin >> H >> W;
    int ans = 0;
    for(int i = 0; i < H; i++){
        string S;
        cin >> S;
        for(auto c:S){
            if(c=='#'){
                ++ans;
            }
        }
    }
    if(ans == H+W-1){
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
}