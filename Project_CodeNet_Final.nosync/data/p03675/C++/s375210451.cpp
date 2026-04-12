#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define REP(i, n) for(int i = 0; i < (n); ++i)
typedef long long ll;
const ll MOD = 1000000007;
using namespace std;

int main(){
    int n; cin >> n;
    int b[n];
    int lt=(n%2 ? n/2 : n/2 -1), rt = (n%2 ? n/2 +1 : n/2);
    REP(i, n){
        int a; cin >> a;
        if((n-i)%2) b[lt--] = a;
        else b[rt++] = a;
    }
    REP(i, n){
        if(i) cout << " ";
        cout << b[i];
    }
    cout << "\n";
    return 0;
}