#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<char> s(3);
    bool flag = false;
    for(int i = 0; i < 3; i++)
        cin >> s[i];
    for(int i = 0; i < 2; i++){
        if(s[i] != s[i + 1])
            flag = true;
    }
    if(flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
}