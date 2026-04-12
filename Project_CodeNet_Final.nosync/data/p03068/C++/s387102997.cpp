#include<iostream>
#include<string>
using namespace std;

int main() {
    int k,n;
    string s;
    char dum;
    cin >> n;
    cin >> s;
    cin >> k;
    dum = s[k-1];
    for(int i=0; i<s.size(); i++){
        if (s[i] != dum) s[i] = '*';
    }
    cout << s << endl;
}