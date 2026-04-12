#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;

    vector<ll> A(N, 0);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<int> min_color(N, 1);
    vector<ll> color_min_val;
    color_min_val.push_back(A[0]);
    for(int i = 1; i < N; i++) {
        auto Iter = lower_bound(color_min_val.begin(), color_min_val.end(), A[i]);
        //int dist = distance(color_min_val.begin(), Iter);
        if(Iter == color_min_val.begin()) {//) {
            color_min_val.insert(color_min_val.begin(), A[i]);
            min_color[i] = min_color[i-1] + 1;
        } 
        else {
            *(Iter-1) = A[i];
            min_color[i] = min_color[i-1];
        }
    }

    cout << min_color[N-1] << endl;

}