#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;

    vector <string> S(H);
    vector <vector <string> > table(H, vector <string> (W));
    for(int i=0; i<H; i++){
        cin >> S[i];
    }

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            table[i][j] = S[i][j];
        }
    }

    vector <int> oki(H,0);
    vector <int> okj(W,0);
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(table[i][j] == "#"){
                oki[i]++;
                okj[j]++;
            }
        }
    }

    for(int i=0; i<H; i++){
        if(oki[i] != 0){
            for(int j=0; j<W; j++){
                if(okj[j] != 0){
                    cout << table[i][j];
                }
            }
            cout << endl;
        }            
    }
}