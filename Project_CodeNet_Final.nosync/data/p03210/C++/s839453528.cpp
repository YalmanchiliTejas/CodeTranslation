#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define ct(string) cout << string << endl

int main() {
    int x;
    cin >> x;
    if (x == 3 || x == 5 || x == 7) ct("YES");
    else ct("NO");
}