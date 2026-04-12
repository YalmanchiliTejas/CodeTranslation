#include<bits/stdc++.h>
using namespace std;
#define itn int

int main(void){
    string s;
    cin >> s;
    bool check = false,check2 = false;
    for(int i = 0;i < s.size();i++){
        if(s[i] == 'A')check = true;
        if(s[i] == 'B')check2 = true;
        
    }
    if(check && check2)cout << "Yes";
    else cout << "No";
}