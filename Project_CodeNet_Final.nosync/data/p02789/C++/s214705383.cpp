#include "iostream"
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    string ans = "No";
    if (N == M) {
        ans = "Yes";
    }
    cout << ans << endl;
    return 0;
}