#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(s,i, n) for (int i = (int)s; i < (int)(n); i++)

int main(){
    string s;
    cin>>s;
    string ans = (s=="AAA"|| s=="BBB") ? "No" :"Yes";
    cout<< ans <<endl;
    return 0;
}