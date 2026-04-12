#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    vector<int> gyo,retu;
    for(int i=0; i<H; i++){
        cin >> a[i];
    }
    string s;
    for(int i=0; i<H; i++){
        s.push_back('.');
    }
    
    for(int i=0; i<H; i++){
        int cnt=0;
        for(int j=0; j<W; j++){
            if(a[i][j]=='.'){
                cnt++;
            }
        }
        if(cnt==W) gyo.push_back(i);
    }
    for(int i=0; i<W; i++){
        int cnt=0;
        for(int j=0; j<H; j++){
            if(a[j][i]=='.'){
                cnt++;
            }
        }
        if(cnt==H) retu.push_back(i);
    }
    
    for(int i=0; i<H; i++){
        bool flag1;
        for(int j=0; j<W; j++){
            bool flag2=true;
            flag1=true;
            for(int k=0; k<gyo.size(); k++){
                if(i==gyo[k]){
                    flag1=false;
                }
            }
            for(int k=0; k<retu.size(); k++){
                if(j==retu[k]){
                    flag2=false;
                }
            }
            if(!flag1) break;
            if(flag2) cout << a[i][j];
        }
        if(flag1)cout << endl;
    }
}

