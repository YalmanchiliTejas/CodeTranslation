#include<bits/stdc++.h>

using namespace std;
int main(){
    string s;
    cin >> s;
    bool test = false;
    for(int i=1; i<=s.size(); i++){
        if(s=="AAA" || s=="BBB")
           test = true;
    }
    if(test)  cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}