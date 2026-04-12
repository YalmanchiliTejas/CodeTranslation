#include<bits/stdc++.h>
using namespace std;

int main(){
    //input
    int H,W;
    cin >> H >> W;

    vector<string> grid(0);

    string s = string(W,'.');

    for(int i=0;i<H;i++){
        string str;
        cin >> str;
        if(str == s)continue;
        grid.push_back(str);
    }

    int v[W] = {0};
    for(int i=0;i<grid.size();i++){
        string str = grid.at(i);
        for(int j=0;j<str.size();j++){
            if(str.at(j) == '#') v[j] = 1;
        }
    }

    for(int i=0;i<grid.size();i++){
        string str = grid.at(i);
        for(int j=0;j<str.size();j++){
            if(v[j]) cout << str.at(j);
        }
        cout << endl;
    }

    return 0;
}