#include <iostream>
using namespace std;

int main()
{
    int H, W;
    string s[100];
    cin >> H >> W;
    for(int i = 0; i < H; i++) cin >> s[i];

    bool h[100], w[100];
    for(int j = 0; j < W; j++) w[j] = false;
    for(int i = 0; i < H; i++){
        h[i] = (s[i].find('#') != -1 ? true : false);
        
        for(int j = 0; j < W; j++){
            if(s[i][j] == '#') w[j] = true;
        }
    }
    
    for(int i = 0; i < H; i++){
        if(!h[i]) continue;
        for(int j = 0; j < W; j++){
            if(!w[j]) continue;
            cout << s[i][j];
        }
        cout << endl;
    }
    return 0;
}