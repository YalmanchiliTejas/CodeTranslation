#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, i, k;
    string s;
    cin >> n >> s >> k;
    for(i=0; i<n; i++){
        if(s[i] == s[k-1]){
            cout << s[i];
        }else{
            cout << '*';
        }
    }
    return 0;
}