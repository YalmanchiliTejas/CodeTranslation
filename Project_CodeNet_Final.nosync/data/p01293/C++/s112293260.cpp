#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    char c;
    string a = "23456789TJQKA";
    while(cin >> c, c != '#'){
        array<array<string, 4>, 13> ss{};
        array<array<int, 4>, 13> sc{};
        for (int j = 0; j < 4; ++j) {
            for (int i = 0; i < 13; ++i) {
                string s;
                cin >> s;
                ss[i][j] = s;
                for (int k = 0; k < a.size(); ++k) {
                    if(s[0] == a[k]) sc[i][j] =  k;
                }
                if(s[1] == c) sc[i][j] += 150;
            }
        }
        int winner = 0;
        int p = 0, q = 0;
        for (int i = 0; i < 13; ++i) {
            for (int j = 0; j < 4; ++j) {
                if(ss[i][winner][1] == ss[i][j][1]) sc[i][j] += 15;
            }
            int yy = max_element(sc[i].begin(),sc[i].end())-sc[i].begin();
            if(yy&1) p++;
            else q++;
            winner = yy;
        }
        if(p > q){
            printf("EW %d\n", p-6);
        }else {
            printf("NS %d\n", q-6);
        }
    }
    return 0;
}
