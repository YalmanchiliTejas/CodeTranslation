#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, k;
    string s;
    char tar;
    cin >> n >> s >> k;

    tar = s[k-1];
    for (int i = 0; i< n; i++){
        if (s[i] != tar)
            s[i] = '*';
    }

    for (int i = 0; i< n; i++)
        cout << s[i];

}
