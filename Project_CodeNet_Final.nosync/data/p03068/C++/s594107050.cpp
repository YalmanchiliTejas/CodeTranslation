#include <iostream>
#include <string>
using namespace std;

int main(){
    int N,K;
    string S;
    
    cin>>N>>S>>K;
    char c=S[K-1];
    for(auto i=0;i<S.length();i++)
        if(S[i]!=c)
            S[i]='*';
    cout<<S<<endl;
    return 0;
}