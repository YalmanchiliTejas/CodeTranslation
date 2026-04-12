#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

lint eq[112][5];
lint lt[112][5];

int main() {
    string s;
    cin >> s;

    lint k;
    cin >> k;

    lint n = s.length();

    eq[0][k] = 1;
    for(lint i=0; i<n; i++)
    for(lint cnt=0; cnt<=3; cnt++) {
        lint a = s[i] - '0';
        if(a == 0) {
            eq[i+1][cnt] += eq[i][cnt];
            lt[i+1][cnt] += lt[i][cnt];
            if(cnt-1 >= 0)  lt[i+1][cnt-1] += 9*lt[i][cnt];
        } else {
            if(cnt-1 >= 0)  eq[i+1][cnt-1] += eq[i][cnt];
            if(cnt-1 >= 0)  lt[i+1][cnt-1] += (a-1) * eq[i][cnt];
            lt[i+1][cnt] += eq[i][cnt];

            if(cnt-1 >= 0)  lt[i+1][cnt-1] += 9*lt[i][cnt];
            lt[i+1][cnt] += lt[i][cnt];
        }
    }

    cout << eq[n][0] + lt[n][0] << endl;
}