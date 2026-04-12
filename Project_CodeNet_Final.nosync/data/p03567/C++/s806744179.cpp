#include <iostream>
#include <string>
using namespace std;

bool ans=false;

int main(){
    string s;cin>>s;
    for(int i=0;i<s.length()-1;i++){
        if(s.substr(i,2)=="AC")ans=true;
    }
    ans ? cout<<"Yes"<<endl : cout<<"No"<<endl;
    return 0;
}