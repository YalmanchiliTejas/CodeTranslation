#define ALL(obj) (obj).begin(), (obj).end()
 
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <functional>
 
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
string S,T,U;
ll A, B;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> S;
    
    if (S[0] == 'A' && S[1] == 'A' && S[2] == 'A') {
        cout << "No" << endl;
    } else if (S[0] == 'B' && S[1] == 'B' && S[2] == 'B') {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    
    return 0;
}
