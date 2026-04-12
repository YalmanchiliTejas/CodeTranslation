#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    if(s[0] == 'A'){
        if(s[1] == 'B' || s[2] == 'B')
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    else{
        if(s[1] == 'A' || s[2] == 'A')
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
