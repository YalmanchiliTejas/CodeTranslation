#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> T(N);
    for(int i=0; i<N; i++) cin >> T[i];

    sort(T.begin(), T.end());
    int target = T.back();

    vector<int> divs;
    for(int i=1; i*i<=target; i++) {
        if(target % i == 0) {
            divs.emplace_back(i);
            if(target / i != i) divs.emplace_back(target / i);
        }
    }
    sort(divs.begin(), divs.end());

    long long int sum = 0;
    for(int i=0; i<N; i++) {
        for(auto d : divs) {
            if(d < T[i]) continue;
            sum += d - T[i];
            break;
        }
    }
    cout << sum << endl;
    return 0;
}

