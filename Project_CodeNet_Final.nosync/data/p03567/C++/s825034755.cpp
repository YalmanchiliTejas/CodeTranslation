#include<iostream>
#include<string>
#include<cstddef>

using namespace std;

int main(){

    int flag=0;
    string S;
    cin >> S;


    if(S.find("A")>=0&&S.find("A")<S.size()){
        if(S.find("C")==1+S.find("A")){
            flag=1;
        }
    }

    if(flag==1){
        cout <<"Yes"<<endl;
    }
    else{
        cout <<"No"<<endl;
    }

    return 0;
}