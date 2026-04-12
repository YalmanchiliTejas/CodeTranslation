#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin>>N;cin.ignore();
    string S;
    getline(cin,S);
    int K;
    cin>>K;
    char not_rep_char;
    not_rep_char=S[K-1];
    for(int i=0;i<N;i++){
        if(S[i]==not_rep_char){
            cout<<not_rep_char;
        }else{
            cout<<"*";
        }
    }
    cout<<endl;
}