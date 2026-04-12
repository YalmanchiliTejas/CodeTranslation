#include <bits/stdc++.h>
using namespace std;
int main(void){
    int h,w;
    cin >>h>>w;
    vector<string> a(h);
    vector<bool> gyo(h, false);
    vector<bool> retsu(w, false);
    
    for(int i=0;i<h;i++) cin >> a[i];
    
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]=='#') gyo[i]= true, retsu[j] = true;
        }
    }
    
    for(int i=0;i<h;i++){
        if(gyo[i]){
            for(int j=0;j<w;j++){
                if(retsu[j]) cout << a[i][j];
            }
            cout << endl;
        }
    }
    
    return 0;
}
