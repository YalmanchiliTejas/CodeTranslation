#include <bits/stdc++.h>
using namespace std;
int main(){
    int h, w;
    cin >> h >> w;
    char a[110][110];
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin >> a[i][j];
        }
    }
    bool tate[110], yoko[110];
    for(int i=1; i<=h; i++){
        yoko[i] = false;
    }
    for(int i=1; i<=w; i++){
        tate[i] = false;
    }
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            if(a[i][j] == '#'){
                yoko[i] = true;
                tate[j] = true;
            }
        }
    }
    for(int i=1; i<=h; i++){
        if(yoko[i]){
            for(int j=1; j<=w; j++){
                if(tate[j]){
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}