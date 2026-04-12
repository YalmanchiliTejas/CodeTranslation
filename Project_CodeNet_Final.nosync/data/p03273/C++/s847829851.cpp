#include <bits/stdc++.h>

using namespace std;

int main(){
    int H,W;
    char a[100][100];
    vector<int> ignoreH,ignoreW;
    cin >> H >> W;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<H;i++){
        bool ignoretmp = true;
        if(a[i][0] == '.'){
            for(int j=0;j<W;j++){
                if(a[i][j] == '#'){ignoretmp = false;}
            }
            if(ignoretmp){
                ignoreH.push_back(i);
            }
        }
    }
    for(int j=0;j<W;j++){
        bool ignoretmp = true;
        if(a[0][j] == '.'){
            for(int i=0;i<H;i++){
                if(a[i][j] == '#'){ignoretmp = false;}
            }
            if(ignoretmp){
                ignoreW.push_back(j);
            }
        }
    }
    for(int i=0;i<H;i++){ 
        bool skiph = false;
        bool skipw = false;
        for(auto iter=ignoreH.begin();iter!=ignoreH.end();iter++){
            if(i == *iter){skiph=true;}
        }
        if(skiph){continue;}
        for(int j=0;j<W;j++){
            for(auto iter=ignoreW.begin();iter!=ignoreW.end();iter++){
                if(j == *iter){skipw=true;}
            }
            if(skipw){skipw=false;continue;}
            cout << a[i][j];
        }
        cout <<endl;
    }
    return 0;
}