#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int MOD = 1000000007;
main(){
    string s[8];
    int H,W,x = 0,y = 0;
    cin >> H >> W;
    for(int i = 0;i < H;i++)cin >> s[i];
    while(x != W-1 || y != H-1){
        s[y][x] = '-';
        if(y == H-1 || (x != W-1 && s[y][x+1] == '#'))x++;
        else y++;
    }
    s[H-1][W-1] = '-';
    for(int i = 0;i < H;i++){
        for(char c:s[i]){
            if(c=='#'){
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    cout << "Possible" << endl;
}