#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;cin >> n;
    string str;cin >> str;
    int k;cin >> k;
    for(int i=0;i<n;i++){
        if(str[i]!=str[k-1])str[i] = '*';
    }

    cout << str << endl;
}