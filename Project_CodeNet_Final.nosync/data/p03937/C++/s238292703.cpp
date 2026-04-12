#include<bits/stdc++.h>
using namespace std;

int main(){
    int h,w,resa,resb,resm=0;
    cin>>h>>w;
    string s[h];
    for(int i=0;i<h;i++){
        cin>>s[i];
    }
    for(int i=0;i<h;i++){
        resa=h;
        for(int j=0;j<w;j++){
            if(s[i][j]=='#'){
                resa=min(resa,j);
                resb=j;
            }
        }
        if(resa<resm){
            cout<<"Impossible"<<endl;
            return 0;
        }
        else resm=max(resm,resb);
    }
    cout<<"Possible"<<endl;
}