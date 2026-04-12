#include <bits/stdc++.h>
using namespace std;
    long long int n, q;
int main() {
    int n, k;
    string s;

    cin >> n >> s >> k;
    for(int i=0;i<s.size();i++){
        if(s[i]!=s[k-1]){
            s[i]='*';
        }
    }
    cout << s << endl;
    return 0;
}