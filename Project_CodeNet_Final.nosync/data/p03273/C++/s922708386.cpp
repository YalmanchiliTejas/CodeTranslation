#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int h,w;cin>>h>>w;
    vector<string> m(h);
    for(int i=0;i<h;++i){
        cin>>m[i];
    }
    vector<bool> hi(h,false);
    vector<bool> wi(w,false);
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            if(m[i][j]=='#'){
                hi[i]=true;
                wi[j]=true;
            }
        }
    }
    for(int i=0;i<h;++i){
        if(hi[i]){
            for(int j=0;j<w;++j){
                if(wi[j]){
                    cout<<m[i][j];
                }
            }
            cout<<endl;
        }
    }
    return 0;
}