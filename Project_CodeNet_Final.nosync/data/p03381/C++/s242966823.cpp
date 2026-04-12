#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<int> X(N);
    for(int i=0; i<N; i++) {
        cin >> X[i];
    }

    vector<int> s = X;
    sort(s.begin(), s.end());
    for(int i=0; i<N; i++) {
        if(X[i] >= s[N/2]) {
            cout << s[N/2-1] << endl;
        } else {
            cout << s[N/2] << endl;
        }
    }
    return 0;
}
