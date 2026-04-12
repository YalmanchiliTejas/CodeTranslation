#include<iostream>
#include<string>

using namespace std;

int main(){

    string str;
    getline(cin, str);

    if(str[0]=='A' && str[1]=='A' && str[2]=='A'){
        cout<<"No";
        return 0;
    }
    if(str[0]=='B' && str[1]=='B' && str[2]=='B'){
        cout<<"No";
        return 0;
    }

    cout<<"Yes";
    return 0;
}