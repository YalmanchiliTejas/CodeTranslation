#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    cin>>str;
    if(str[0]==str[1]&&str[1]==str[2]&&str[0]==str[1]){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    return 0;
}