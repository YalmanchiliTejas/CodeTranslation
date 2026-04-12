#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

int main() {

    int N;
    cin >> N;

    int h;
    int count = 0;
    int max_h = 0;
    for (int i = 0; i<N; i++) {
        cin >> h;
        if (h >= max_h) {
            count++;
            max_h = h;
        }
    }

    cout << count << endl;

    return 0;
}
