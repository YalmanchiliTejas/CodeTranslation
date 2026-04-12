#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    char c[1010][1010];
    for(int i = 0;i < h;i++){
        cin >> c[i];
    }

    char ans[1010][1010];
    int ap = 0;
    for(int i = 0;i < h;i++){
        bool flag = true;
        for(int j = 0;j < w;j++){
            if(c[i][j] != '.'){
                flag = false;
            }
        }
        if(!flag){
            for(int j = 0;j < w;j++){
                ans[ap][j] =c[i][j];
            }
            ap++;
        }
    }

    char ans2[1010][1010];
    int ap2 = 0;
    for(int i = 0;i < w;i++){
        bool flag = true;
        for(int j = 0;j < ap;j++){
            if(ans[j][i] != '.'){
                flag = false;
            }
        }
        if(!flag){
            for(int j = 0;j < ap;j++){
                ans2[j][ap2] =ans[j][i];
            }
            ap2++;
        }
    }

    for(int i = 0;i < ap;i++){
        for(int j = 0;j < ap2;j++){
            cout << ans2[i][j];
        }
        cout << endl;
    }

    return 0;
}
