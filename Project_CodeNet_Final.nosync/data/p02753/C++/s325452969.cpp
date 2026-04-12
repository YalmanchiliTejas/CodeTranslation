#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
using namespace std;
int main() {
    int a=0, b=0;
    string s;
    cin >> s;
    for (int i = 0; i < 3; i++) {
        if (s[i] == 'A') {
            a++;
        }
        else {
            b++;
        }
    }
    if (a == 2 || b == 2) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}