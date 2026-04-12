#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
#include<sstream>
#include<cmath>
//#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n, m;string s;
    cin >> n >> s >> m;
    rep(i, n) {
        if (s[i] != s[m - 1])
            s[i] = '*';
    }
    cout << s << endl;
}