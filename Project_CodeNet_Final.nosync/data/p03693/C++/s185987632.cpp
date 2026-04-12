#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, k, n) for(int i = (k); i < (int)(n); i++)
using namespace std;
int main(){
    int r, g, b;
    cin >> r >> g >> b;
    int sum = 100 * r + 10 * g + b;
    if(sum % 4 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}