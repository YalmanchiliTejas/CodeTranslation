#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    for(int i = 0; i < n; i++){
        if(s.at(i) != s.at(k-1)){
            s.at(i) = '*';
        }
    }
    cout << s << endl;
}
