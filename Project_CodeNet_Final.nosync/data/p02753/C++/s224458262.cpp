#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s; cin >> s;
    for(int i=0;i<2;i++){
        if(s[i]=='A'&&s[i+1]=='B' || s[i]=='B'&&s[i+1]=='A'){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}