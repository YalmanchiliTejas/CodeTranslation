#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H,W;
    cin >> H >> W;
    vector<string> S(H);
    for(int i=0; i<H; i++){
        cin >> S[i];
    }
    vector<bool> yoko(W, false);
    vector<bool> tate(H,false);
    
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(S[i][j] == '#'){
                yoko[j] = true;
                tate[i] = true;
            }
        }
    }
    for(int i=0; i<H; i++){
        if(tate[i] == true){
            for(int j=0; j<W; j++){
                if(yoko[j] == true){
                    cout << S[i][j];
                }
            }
            cout << endl;
        }
    }
}

