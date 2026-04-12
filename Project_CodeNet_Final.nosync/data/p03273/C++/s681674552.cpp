#include <bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> a(h,vector<char>(w));
    vector<vector<char>> b(w,vector<char>(h));
    vector<char> flagElementH(h,'.');
    vector<char> flagElementW(w,'.');
    vector<bool> flagH(h,false);
    vector<bool> flagW(w,false);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> a.at(i).at(j);
            b.at(j).at(i) = a.at(i).at(j);
        }
    }
    for(int i=0;i<h;i++){
        if(a.at(i) == flagElementW){
            flagH.at(i) = true;
        }
    }
    for(int i=0;i<w;i++){
        if(b.at(i) == flagElementH){
            flagW.at(i) = true;
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(flagH.at(i) || flagW.at(j)){
                continue;
            }
            cout << a.at(i).at(j);
        }
        if(flagH.at(i)) continue;
        cout << endl;
    }
}