#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    bool k = 0;
    for(int i = 0; i < n-1; i++){
        if(s[i] == 'A' && s[i+1] == 'C'){
            k = 1;
        }
    }
    if(k == 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
