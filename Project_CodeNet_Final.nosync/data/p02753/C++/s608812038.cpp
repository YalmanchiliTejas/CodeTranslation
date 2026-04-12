#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    bool ans=true;
    if(s.at(0)==s.at(1) && s.at(1)==s.at(2))ans=false;
    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
