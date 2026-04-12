#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array


void solve(){
    string s;
    cin >> s;
    int a = 0, b = 0;
    for(int i = 0; i < 3; ++i){
        if(s.at(i) == 'A'){
            a++;
        } else {
            b ++;
        }
    }
    if(a > 0 && b > 0){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testCases;
    testCases = 1;
    while(testCases --){
        solve();
    }
}
