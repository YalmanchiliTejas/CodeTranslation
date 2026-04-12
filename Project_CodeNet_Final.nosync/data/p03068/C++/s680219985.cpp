#include <bits/stdc++.h>
using namespace std;
#define LL long int

const LL MOD = pow(10,9) + 7;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;

    for(int i = 0; i < n; ++i){
        if(s[i] == s[k - 1]){
            cout << s[i];
        }else{
            cout << '*';
        }
    }

    cout << endl;

    return 0;
}