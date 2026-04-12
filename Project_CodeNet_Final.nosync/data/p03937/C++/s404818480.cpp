#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
int main(void){
    // Your code here!
    int h,w;
    cin>>h>>w;
    int p=0;
    for(int i=0;i<h;i++){
        string s;
        cin>>s;
        for(int j=0;j<w;j++){
            if(s[j]=='#')p++;
        }
    }
    if(p==w+h-1)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}