#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<int>> hoge(h,vector<int>(w));
    vector<bool> tate(w,false);
    vector<bool> yoko(h,false);
    vector<string> maps(h);
    
    for(int i=0;i<h;i++){
        string tmp;
        cin>>tmp;
        for(int k=0;k<w;k++){
            if(tmp.at(k)=='#'){
                tate.at(k)=true;
                yoko.at(i)=true;
            }
        }
        maps.at(i)=tmp;
    }
    
    for(int i=0;i<h;i++){
        bool ok=false;
        for(int k=0;k<w;k++){
            if(tate.at(k)==true && yoko.at(i)==true) {cout<<maps.at(i).at(k);ok=true;}
        }
        if(ok) cout<<endl;
    }
    
    return 0;
}