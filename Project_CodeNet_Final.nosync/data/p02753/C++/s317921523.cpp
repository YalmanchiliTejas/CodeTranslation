#include <iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    char fir = s[0];
    for(int i=1;i<s.length();i++){
        if(s[i]!=fir){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}