#include <iostream>
#include <string>
using namespace std;
int main(void){
    string S;
    cin>>S;
    for(int i=0;i<4;i++){
        if(S[i]=='A' && S[i+1]=='C'){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}