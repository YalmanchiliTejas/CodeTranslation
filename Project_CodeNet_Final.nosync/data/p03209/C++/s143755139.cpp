#include<bits/stdc++.h>
using namespace std;

vector<int64_t> layer(51);
vector<int64_t> patty(51);

int64_t sumpatty(int64_t dim, int64_t toeat) {
    if (dim == 0 || toeat == 0) return toeat;
    if (layer[dim] - 1 <= toeat) return patty[dim];
    if (layer[dim-1] + 2 <= toeat) return patty[dim-1] + 1 + sumpatty(dim - 1, toeat - layer[dim-1] - 2);
    return sumpatty(dim - 1, toeat - 1);
}

int main() {
    int64_t n, x;
    cin >> n >> x;

    layer[0] = patty[0] = 1;
    for (int i = 0; i + 1 <= n; i++) {
        layer[i+1] = 2 * layer[i] + 3;
        patty[i+1] = 2 * patty[i] + 1;
    }

    cout << sumpatty(n, x) << endl;
}
