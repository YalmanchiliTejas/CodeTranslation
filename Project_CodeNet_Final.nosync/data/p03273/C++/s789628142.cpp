#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w;cin>>h>>w;
    vector<vector<char>> a(h,vector<char>(w));
    vector<bool> row(h,true);
    vector<bool> col(w,true);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a.at(i).at(j);
            if(a.at(i).at(j)=='#'){
                row[i]=false;
                col[j]=false;
            }
        }
    }
    for(int i=0;i<h;i++){
        if(row[i]==false){
            for(int j=0;j<w;j++){
                if(col[j]==false){
                    cout<<a.at(i).at(j);
                }
            }
            cout<<endl;
        }
    }
}