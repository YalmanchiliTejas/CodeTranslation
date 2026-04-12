#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    cin>>str;
    for (int i=0; i<sizeof(str); i++) {
        if(str[i]=='A'&&str[i+1]=='C'){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}