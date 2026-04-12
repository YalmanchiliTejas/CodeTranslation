#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long N;
    long long A[100000];
    cin >> N;
    for (int i=0; i<N; i++) cin >> A[i];
    
    vector<int> color(N);
    for (int i=0; i<N; i++) {
        color[i] = 1;
    }
    int head = 1;
    for (int i=0; i<N; i++) {
        long long item = -A[i];
        int idx = upper_bound(color.begin(), color.begin()+head, item) - color.begin();
        color[idx] = item;
        if (idx == head-1) {
            head++;
        }
    }
    int s = 0;
    for (int i=0; i<N; i++) {
        if (color[i] == 1) break;
        s++;
    }
    cout <<  s << endl;
    return 0;
}

