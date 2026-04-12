#include <iostream>
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <cmath>
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long N,X;
    cin >> N>>X;
    long long sou, pat,maisuu;
    pat = 0;
    sou = X;
    for (int i = 0; i < N; i++) {
        maisuu = 1;

        for (int j = i; j <N; j++) {
            maisuu = 2*maisuu+3;
        }
        if (sou < 1) {
            break;
        }
        else {
            if (sou > (maisuu - 1) / 2 && maisuu != 5) {
                sou -= (maisuu + 1) / 2;
                pat += (maisuu + 3) / 4;
            }
            else if (maisuu != 5) {
                sou--;
            }
            else if (sou > 4) {
                pat += 3;
                break;
            }
            else {
                pat += sou - 1;
                break;
            }
        }
    }
         
    cout << pat << endl;
}