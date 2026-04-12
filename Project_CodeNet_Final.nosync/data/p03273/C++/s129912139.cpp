#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> math(h);
    int cntflag=0;
    vector<bool> flag(h,false),tate(w,false);
    for(int i=0; i<h; i++){
        bool white=true;
        for(int j=0; j<w; j++){
            char tmp;
            cin >> tmp;
            math[i].push_back(tmp);
            if(tmp=='#')white=false;
        }
        if(white){
            cntflag++;
            flag[i]=true;
        }

    }
    for(int i=0; i<w; i++){
        bool white=true;
        for(int j=0; j<h; j++){
            if(math[j][i]=='#')white=false;
        }
        if(white)tate[i]=true;
    }
    vector<vector<char>> ans(h-cntflag);
    for(int i=0; i<h; i++){
        if(flag[i])continue;
        for(int j=0; j<w; j++){
            if(tate[j])continue;
            cout << math[i][j];
        }
        cout << endl;
    }

}