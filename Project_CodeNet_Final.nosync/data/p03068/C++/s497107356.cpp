/*
 * Created by Dipta Das on 20-04-2019
 * Title: 
 * Problem Link: 
 * Editorial: 
 * Source Code: 
 * Comments: 
*/

#include <bits/stdc++.h>
#include <stdio.h>
#define fin freopen("input", "r", stdin)
#define whatis(x) cerr << #x << ": " << x << endl;

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    int k;
    string s;

    cin >> n;
    cin >> s;
    cin >> k;


    for (int i = 0; i < n; ++i) {
        if (s[i] != s[k - 1] && i != k - 1) {
            s[i] = '*';
        }
    }
    cout << s << endl;

    


    return 0;
}

