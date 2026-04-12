#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int,int> PP;

/*
    freopen("input","r",stdin);
    freopen("output","w",stdout);
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> A, B;
    int N;
    cin >> N;
    A.resize(N);
    for (int i = 0;i < N;i++) cin >> A[i];
    B = A;
    sort(B.begin(), B.end());
    int idx = N / 2 - 1;
    for (int i = 0;i < N;i++) {
    	if (A[i] <= B[idx]) cout << B[idx + 1];
    	else cout << B[idx];
    	cout << endl;
    }
    return 0;
}