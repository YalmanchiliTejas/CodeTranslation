#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> P;
typedef pair<int64_t, int64_t> Pll;
  
int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    cout << (X - Z) / (Y + Z) << endl;
}