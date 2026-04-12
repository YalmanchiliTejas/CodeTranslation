#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char> >c(h,vector<char>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> c[i][j];
        }
    }
    bool chk = true;
    while(chk){
        chk = false;
        vector<int>tmp;
        for(int i=0;i<h;i++){
            bool chkk = true;
            for(int j=0;j<w;j++){
                if(c[i][j] == '#')chkk = false;
            }
            if(chkk){
                tmp.push_back(i);
                chk=true;
            }
        }
        h -= tmp.size();
        for(int i=tmp.size()-1;i>=0;i--){
            c.erase(c.begin() + tmp[i]);
        }
        vector<int>tmpp;
        for(int i=0;i<w;i++){
            bool chkk = true;
            for(int j=0;j<h;j++){
                if(c[j][i] == '#')chkk=false;
            }
            if(chkk){
                tmpp.push_back(i);
                chk=true;
            }
        }
        w -= tmpp.size();
        for(int i=tmpp.size()-1;i>=0;i--){
            for(int j=0;j<h;j++){
                c[j].erase(c[j].begin() + tmpp[i]);
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
cout << c[i][j];
        }
        cout << endl;
        
    }
}