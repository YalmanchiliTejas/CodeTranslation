#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    string s;

    cin >> s;

    int a = 0, b = 0;

    for(int i=0; i<3; i++){
        if(s[i] == 'A') a++;
        else b++;
    }

    if(a>=1 and b>=1) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
