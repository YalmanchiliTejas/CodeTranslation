#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <list>
#include <queue>
using namespace std;

int inf = (1 << 30);
int mod = 1e9 + 7;
int64_t inf64 = (1LL << 60);

template <typename T>
T gcd(T a, T b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

template <typename T>
T lcm(T a, T b) {
    T g = gcd(a, b);
    return a / g * b;
}

bool check(vector<int> a, int index, int key){
    if(a[index] >= key) return true;
    else return false;
}

int lower_bound(vector<int> a, int key){
    int left = -1, right = a.size();
    while(right - left > 1){
        int mid = left + (left + right) / 2;
        if(check(a, mid, key)) right = mid;
        else left = mid;
    }
    return right;
}

int main(){

    int N;
    cin >> N;

    cout << (800 * N) - 200 * (N / 15) << endl;

    return 0;
}