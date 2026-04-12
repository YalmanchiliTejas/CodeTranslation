#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<algorithm>
#include <utility>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)


int main(){
    char S[3];
    cin >> S;
    if(S[0]==S[1]&&S[1]==S[2]){
        cout << "No"<< endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}
