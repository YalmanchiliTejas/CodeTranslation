#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
using namespace std;

int main(){
    int i, j;
    string s;
    cin >> s;
    if((s[0]=='A' && s[1]=='A' && s[2]=='A') ||
      (s[0]=='B' && s[1]=='B' && s[2]=='B') )
    {
        cout << "No";
    } 
    else
    {
        cout << "Yes";
    }
}