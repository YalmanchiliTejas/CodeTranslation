#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>>vec(h,vector<char>(w));
    vector<vector<bool>>out(h,vector<bool>(w,true));
    bool bou;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>vec[i][j];
        }
    }
    for(int i=0;i<h;i++){
        bou=true;
        for(int j=0;j<w;j++){
            if(vec[i][j]!='.'){
                bou=false;
                break;
            }
        }
        if(bou){
            for(int j=0;j<w;j++){
                out[i][j]=false;
            }
        }
    }
     for(int i=0;i<w;i++){
        bou=true;
        for(int j=0;j<h;j++){
            if(vec[j][i]!='.'){
                bou=false;
                break;
            }
        }
        if(bou){
            for(int j=0;j<h;j++){
                out[j][i]=false;
            }
        }
    }
    for(int i=0;i<h;i++){
    	bou=false;
        for(int j=0;j<w;j++){
            if(out[i][j]){
                cout<<vec[i][j];
                bou=true;
            }
        }
        if(bou){
        	cout<<endl;
        }
    }
}
