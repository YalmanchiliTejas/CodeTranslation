#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    char c;
    cin>>c;
    bool ans=false;
    string vowel = "aiueo";
    for (int i=0;i<5;i++){
        if (vowel[i]==c) ans=true;
    }
    if (ans) cout<<"vowel"<<endl;
    else cout<<"consonant"<<endl;
    return 0;
}