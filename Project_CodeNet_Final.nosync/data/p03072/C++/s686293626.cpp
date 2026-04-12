#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {
    int N;
    cin >> N;
    int now_H = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        if (now_H <= temp) count++;
        now_H = max(now_H, temp);
    }
    cout << count << endl;
    return 0;
}