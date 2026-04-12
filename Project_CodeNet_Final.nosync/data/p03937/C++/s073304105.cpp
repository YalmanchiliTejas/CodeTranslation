#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;


int main() {
   int h, w;
    cin >> h >> w;
    int count = 0;
    for (int i = 0; i < h; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < w; j++) {
            count += str[j] == '#';
        }
    }
    cout << (count==h+w-1 ? "Possible" : "Impossible");
}
