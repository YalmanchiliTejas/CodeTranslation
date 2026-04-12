#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
bool func(){
    string str;
    cin>>str;
    for(int i=0;i<str.size()-1;++i){
        if(str.substr(i,2)=="AC"){
            return true;
        }
    }
    return false;
}
int main(){
    cout<<(func()?"Yes":"No")<<endl;
}