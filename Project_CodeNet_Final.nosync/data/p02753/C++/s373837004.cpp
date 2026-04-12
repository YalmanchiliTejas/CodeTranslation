#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string s;
    cin >> s;

    int is_diff = 0;

    for(int i = 0; i < 2; i++) {
        if(s[i] != s[i + 1]) is_diff = 1;
    }

    if(is_diff) cout << "Yes\n";
    else cout << "No\n"; 


    
}
