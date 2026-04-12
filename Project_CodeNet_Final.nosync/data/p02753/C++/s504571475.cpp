#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(void){
    string s,ans = "Yes";
    cin >> s;
    
    if(s[0] == s[1] && s[0] == s[2]) ans ="No";

    cout << ans << endl;

    return 0;
}