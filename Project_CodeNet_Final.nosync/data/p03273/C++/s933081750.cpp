#include<iostream>
#include<vector>
using namespace std;

int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>> a(h,vector<char>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++) cin>>a[i][j];
    }

    vector<bool> y(h,false),x(w,false);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]=='#'){
                y[i]=true;
                x[j]=true;
            }
        }
    }
    for(int i=0;i<h;i++){
        if(y[i]){
            for(int j=0;j<w;j++){
                if(x[j]) cout<<a[i][j];
            }
            cout<<endl;
        }
    }
}