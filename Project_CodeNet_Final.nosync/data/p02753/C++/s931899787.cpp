#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s; cin >> s;
    for(int i = 0; i < 2; i++){
        if(s[i] != s[(i+1)%3]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}