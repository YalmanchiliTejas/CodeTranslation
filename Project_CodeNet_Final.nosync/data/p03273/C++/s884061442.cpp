#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,w,fl=0;
    cin >> h >> w;
    vector<vector<char>> haha(h,vector<char>(w));
    for(int i=0;i<h;i++){
        for(int ii=0;ii<w;ii++){
            cin >> haha.at(i).at(ii);
            if(haha.at(i).at(ii)!='.'){
                fl=1;
            }
        }
        if(fl == 0){
            i--;
            h--;
        }
        fl=0;
    }
    for(int i=0;i<w;i++){
        for(int ii=0;ii<h;ii++){
            if(haha.at(ii).at(i)!='.'){
                fl=1;
            }
        }
        if(fl == 0){
            for(int m=i;m<w-1;m++){
                for(int ii=0;ii<h;ii++){
                    haha.at(ii).at(m) = haha.at(ii).at(m+1);
                }
            }
            w--;
            i--;
        }
        fl=0;
    }
    for(int i=0;i<h;i++){
        for(int ii=0;ii<w;ii++){
            cout << haha.at(i).at(ii);
        }
        cout << endl;
    }


    
}