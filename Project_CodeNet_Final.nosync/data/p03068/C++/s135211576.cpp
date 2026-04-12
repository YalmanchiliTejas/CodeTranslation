#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
#include <queue>
#include <map>
#include <set> 
#include <bitset>
#include <cmath>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<n;i++)
int main () {
    
    int n; cin >> n;
    string s; cin >> s;
    int k; cin >> k;

    char a = s[k-1];
    for (int i = 0; i < s.length(); i++) {
        if(s[i] != a) {
            s[i] = '*';
        } 
    }

    cout << s << endl;
    
    return 0;
}

