#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> map(H);
    vector<vector<int>> flag(H,vector<int>(W));
    vector<int> Hdelete(H);

    for(int i=0;i<H;i++){
        cin >> map[i];
    }

    for(int i=0;i<H;i++){
        int cnt =0;
        for(int j=0;j<W;j++){
            if(map[i][j]=='.') cnt++;
        }
        if(cnt==W){
            Hdelete[i]=1;
            for(int j=0;j<W;j++){
                flag[i][j]=1;
            }
        }
    }

    for(int j=0;j<W;j++){
        int cnt =0;
        for(int i=0;i<H;i++){
            if(map[i][j]=='.') cnt++;
        }
        if(cnt==H){
            for(int i=0;i<H;i++){
                flag[i][j]=1;
            }
        }
    }

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(flag[i][j]==0) cout << map[i][j];
        }
        if(Hdelete[i]==0) cout << endl;
        
    }
    
}