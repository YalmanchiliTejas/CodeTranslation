#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool c[10][10];
int main(){
    int h,w;
    string ans = "Possible";
    cin >> h >> w;
    for(int i = 0;i < h;i ++){
        for(int j = 0;j < w;j ++){
            char a;
            cin >> a;
            if(a=='#') c[i][j] = 1;
        }
    }
    for(int i = 0;i < h-1;i ++){
        for(int j = 0;j < w-1;j ++){
            if(c[i+1][j]&&c[i][j+1]&&c[i+1][j+1]) ans = "Impossible";
            if(c[i][j]&&c[i][j+1]&&c[i+1][j]) ans = "Impossible";            
        }
    }
    cout << ans << endl;
    return 0;
}