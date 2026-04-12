#include "bits/stdc++.h"
using namespace std;

int main(){
    int N,K;
    string str;
    cin >> N;
    cin >> str;
    cin >> K;
    char c=str[K-1];
    for(int i=0;i<str.length();i++){
        if(str[i]!=c) str[i]='*';
    }
    cout << str << endl;
    return 0;
}