#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int counta=0;
    for(int i=0; i<3; i++){
        if(s[i]=='A'){
            counta++;
        }
    }
    if(counta != 0 && counta != 3){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
    return 0;
}
