#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;    
    vector<string> a;
    for(int i=0; i<H; i++){
        string s;
        cin >> s;
        for(int j=0; j<W; j++){
            if(s[j]=='#'){
                a.push_back(s);
                break;
            }
        }
    }
    H = a.size();
    for(int i=W-1; i>=0; i--){
        bool dup = true;
        for(int j=0; j<H; j++){
            if(a[j][i]=='#') {
                dup = false;
                break;
            }
        }
        if(!dup) continue;
        for(int j=0; j<H; j++){
            a[j].erase(a[j].begin()+i);
        }
    }

    for(int i=0; i<H; i++){
        cout << a[i] << endl;
    }
}
