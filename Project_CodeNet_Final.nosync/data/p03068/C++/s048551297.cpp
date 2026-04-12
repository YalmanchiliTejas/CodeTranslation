#include<iostream>

using namespace std;

int main(){
    int N;
    string str1;
    int K;
    
    cin>>N>>str1>>K;
    for(int i = 0; i < N;i++){
        //置き換える
        if(str1.at(i) != str1.at(K-1)){
            cout<<"*";
        }
        //置き換えない
        else{
            cout<<str1.at(i);
        }
    }
    cout<<endl;
    return 0;
    }
