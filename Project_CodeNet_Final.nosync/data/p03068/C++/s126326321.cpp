#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    string s;
    char ck;
    cin >> n >> s >> k;
    ck = s[k-1];
    for(int i=0;i<n;i++){
        if( s[i] != ck){
            s[i] = '*';
        }
    }
    cout << s;
}