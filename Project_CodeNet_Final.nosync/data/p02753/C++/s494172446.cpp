#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    string s; cin >> s;
    if(s[0] != s[1] || s[1] != s[2]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}