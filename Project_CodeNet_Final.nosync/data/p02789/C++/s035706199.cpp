#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
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

int my_abs_A(int num) {
    if (num > 0)
        return num;
    else
        return -num;
}

int my_abs_B(long long num,long long numb) {
    if (num - numb >= 0)
        return num - numb;
    else
        return -1 * (num - numb);
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

int main() {
    int A, B;
    cin >> A >> B;
    if (A == B) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
