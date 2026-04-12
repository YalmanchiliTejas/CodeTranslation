#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    string s;
    cin >> n >> s >> k;
    k -= 1;

    for(int i=0; i<n; i++){
        if(s[i] != s[k]) s[i] = '*';
    }
    cout << s << endl;
    return 0;
}