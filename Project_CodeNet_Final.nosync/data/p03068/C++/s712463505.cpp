#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int n,k;
    cin >> n >> s >> k;
    for(int i=0;i<n;i++){
        if(s.at(i)!=s.at(k-1)){
            s.at(i)='*';
        }
    }
    cout << s << endl;
}
