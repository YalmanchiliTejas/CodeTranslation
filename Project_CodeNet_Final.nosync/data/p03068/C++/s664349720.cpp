#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    string s;
    cin >> n >> s >> k;
    char str = s[k-1];
    for(int i=0;i<n;i++){
        if(str!=s[i]) cout << '*';
        else cout << str;
    }
    cout << endl;
    return 0;
}
