//
//  main.cpp
//  ABC158A
#include <iostream>
#include<string>
using namespace std;
int main(int argc, const char * argv[]) {
    string S;
    cin>>S;
    char TMP=S.at(0);
    if (S.at(1)!=TMP||S.at(2)!=TMP) {
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}
