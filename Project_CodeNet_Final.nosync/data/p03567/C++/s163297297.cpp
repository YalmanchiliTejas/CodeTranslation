#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    bool flag = false;
    for(int i = 0; i < n-1; i++){
        if(s[i] == 'A' && s[i+1] == 'C') flag = true;
    }    
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}