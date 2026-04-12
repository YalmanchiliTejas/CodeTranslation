#include<iostream>
#include<string>
using namespace std;

int main(){
    string S;
    cin>>S;
    if(S[1]=='A'){
        if(S[0]=='B'||S[2]=='B'){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    else{
        if(S[0]=='A'||S[2]=='A'){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}