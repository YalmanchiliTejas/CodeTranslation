#include<iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int frg=0;
    for(int i=1;i<s.size();i++){
        if(s[i-1]=='A' && s[i]=='C')frg=1;
    }
    if(frg)cout << "Yes" <<  endl;
    else cout << "No" << endl;
}
