#include<bits/stdc++.h>  
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout.precision(30);
    string s;
    int a,b;
    cin>>s;
    a=0;b=0;
    for(int i=0;i<3;i++){
        if(s[i]=='A'){
            a++;
        }
        else{
            b++;
        }

    }
    if(((a==2)&&(b==1))||((a==1)&&(b==2))){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}