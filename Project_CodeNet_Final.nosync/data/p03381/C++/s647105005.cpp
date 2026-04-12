#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <map>

#define rep(i, N) for(int (i) = 0; (i) < (N); (i) ++)
typedef long long ll;

using namespace std;

int main(){
    int N;
    cin >> N;
    // Nは偶数.
    vector<int> xs(N, 0);
    vector<int> ys(N, 0);
    rep(i, N){
        cin >> xs[i];
        ys[i] = xs[i];
    }
    sort(xs.begin(), xs.end());

    rep(i, N){
        // Nは偶数.
        int med = xs[N / 2 - 1];
        if(ys[i] <= med){
            med = xs[ N / 2];
        }
        cout << med << endl;
    }

    return 0;
}
