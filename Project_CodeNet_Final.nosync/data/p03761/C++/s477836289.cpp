#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define ll long long
#define imfor(i, n) for(int i = 0; i < n; i++)
using namespace std;
ll MOD = 1000000007;

int main() {
    int n;
    string s[50];
    cin >> n;
    imfor(i, n) {
        cin >> s[i];
    }
    int minc[26];
    fill(minc, minc + 26, 99);
    imfor(i, n) {
        map<char, int> mp;
        imfor(j, s[i].size()) {
            mp[s[i][j]] += 1;
        }
        imfor(j, 26) {
            char c = 'a' + j;
            if (mp[c] < minc[j]) {
                minc[j] = mp[c]; 
            }
        }
    }
    imfor(i, 26) {
        char c = 'a' + i;
        imfor(j, minc[i]) {
            cout << c;
        }
    }
    cout << endl;
}