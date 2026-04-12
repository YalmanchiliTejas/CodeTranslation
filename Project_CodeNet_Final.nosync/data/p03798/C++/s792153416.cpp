#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin >> N;
    string s; cin >> s;
    //1 : 羊 , -1 : 狼
    int shoki[4][2] ={{1,1},{1,-1},{-1,1},{-1,-1},};
    int flag = 0;
    for (int i=0;i<4;i++){
        int hype[N+2]; hype[0]= shoki[i][0]; hype[1]= shoki[i][1];
        for (int j=0;j<N;j++){
            if(s[j]=='o') hype[j+2]= hype[j+1]*hype[j];
            else hype[j+2]= -hype[j+1]*hype[j];
        }
        if ((hype[0]==hype[N])&&(hype[1]==hype[N+1])){
            for (int j=0;j<N;j++){
                if (hype[j+1]==1) cout << "S";
                else cout << "W";
                if (j==N-1) cout << "\n";
            }
            flag = 1;
        }
        if (flag) break;
    }
    if (!flag) cout << -1 << "\n";
}