// 

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <map>
#include <cmath>
#include <stack>

#define REP(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;

int main(){
    string s;
    cin >> s;
    if((s[0] == s[1]) && (s[1] == s[2])) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
