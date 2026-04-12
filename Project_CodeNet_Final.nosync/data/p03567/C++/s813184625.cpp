#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    for(ll i = 0;i < s.size();i++){
        if(s[i] == 'A' and i + 1 < s.size() and s[i+1] == 'C'){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
