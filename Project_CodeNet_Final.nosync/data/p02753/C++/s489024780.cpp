#include<bits/stdc++.h>

using namespace std;
int main(){
    string s;
    cin>>s;
    int flag=1;
    for(int i=0;i<3;i++){
        if((s[i]=='A' && s[i+1]=='B')||(s[i]=='B'&&s[i+1]=='A')){
            cout<<"Yes"<<endl;
            flag=0;
            break;
        }
    }
    if(flag==1){
        cout<<"No"<<endl;
    }
}