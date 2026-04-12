#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>

using namespace std;
using llong = long long;
const int MOD=1000000007;


int main(int argc, char**argv){
    int n;
    string s;
    int k;
    cin >> n;
    cin >> s;
    cin >> k;

    for (int i = 0 ; i < n; i++){
        if (s[i] != s[k-1]) cout << '*';
        else cout << s[i];
    }
    cout << endl;


    return 0;
}










