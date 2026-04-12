#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FOR(i, n) for(int i = 0; i < (n); i ++)
#define CIN(type, val) type val; cin >> val;
#define COUT(val) cout << (val) << "\n";
using namespace std;

int main(void){
    CIN(int, n);
    COUT(n == 7 || n == 5 || n == 3 ? "YES" : "NO");
}