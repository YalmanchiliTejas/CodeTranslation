#include <iostream>

using namespace std;

int main(){
    char S[3];
    cin>>S;
    //cout<<S[0]<<":"<<S[1]<<":"<<S[0]<<'\n';
    
    if((S[0]=='A'&&S[1]=='A'&&S[2]=='A')||(S[0]=='B'&&S[1]=='B'&&S[2]=='B')){
        cout<<"No"<<'\n';
    }else{
        cout<<"Yes"<<'\n';
    }
    
}
