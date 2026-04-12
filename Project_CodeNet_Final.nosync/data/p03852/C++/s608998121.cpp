#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    string s="aiueo";
    string t;
    cin>>t;
    bool f=false;
    for(int i=0;i<5;i++){
        if(s[i]==t[0]){
            f=true;
        }
    }
    if(f){
        cout<<"vowel"<<endl;
    }else{
        cout<<"consonant"<<endl;
    }
}
