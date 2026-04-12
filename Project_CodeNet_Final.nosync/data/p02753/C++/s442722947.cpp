#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin>>S;
    bool flag = true;
    if(S=="AAA"){
        flag = false;
    }else if(S=="BBB"){
        flag = false;
    }
    
    if(flag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}
