#include <bits/stdc++.h>
using namespace std;


int main() {
    string s;
    cin >> s;
    int a=0;
    int b=0;
    for(int i=0;i<3;i++){
        if('A'==s[i]){
            a++;
        }else if('B'==s[i]){
            b++;
        }
    }
    if(a==3||b==3){
        cout << "No" << endl;
        return 0;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}