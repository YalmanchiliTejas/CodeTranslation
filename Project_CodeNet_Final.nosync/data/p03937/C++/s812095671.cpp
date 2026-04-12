#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int h,w; cin >> h >> w;
    char a[h+2][w+2];
    for(int i = 0; i < h+2; i++){
        for(int j = 0; j < w+2; j++){
            a[i][j] = '.';
        }
    }

    int c = 0;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> a[i][j];
            if(a[i][j] == '#') c++;
        }
    }
    int i = 1, j = 1;
    while(i != h || j != w){
        if(a[i+1][j] == '#'){i++; c--; continue;}
        if(a[i][j+1] == '#'){j++; c--; continue;}
        else break;
    }
    if(c == 1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;

    return 0;
}