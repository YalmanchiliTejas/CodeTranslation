#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int h,w;
    cin >> h >> w;
    int a[h];
    int b[w];
    for(int i = 0; i < h; i++){
        a[i] = 0;
    }
    for(int i = 0; i < w; i++){
        b[i] = 0;
    }
    char c[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> c[i][j];
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(c[i][j] == '#'){
                a[i] = 1;
                b[j] = 1;
            }
        }
    }
    for(int i = 0; i < h; i++){
        int t = 0;
        for(int j = 0; j < w; j++){
            if(a[i] == 1 && b[j] == 1){
                cout << c[i][j];
                t = 1;
            }
        }
        if(t == 1) cout << '\n';
    }
}