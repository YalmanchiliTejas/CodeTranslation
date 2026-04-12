#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int h,w;
    cin>>h>>w;
    vector<string> s(h);
    for(int i=0;i<h;i++){
        cin>>s[i];
    }
    vector<bool> P1(h,true);
    vector<bool> P2(w,true);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=='#'){
                P1[i]=false;
                P2[j]=false;
            }
        }
    }
    for(int i=0;i<h;i++){
        if(!P1[i]){
            for(int j=0;j<w;j++){
                if(!P2[j]){
                    cout<<s[i][j];
                }
            }
            cout<<endl;
        }
    }
}
