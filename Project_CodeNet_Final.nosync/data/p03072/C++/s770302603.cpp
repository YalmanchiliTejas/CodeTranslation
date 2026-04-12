#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i< N; i++) {
        cin >> H[i];
    }

    int res = 0;
    int h = 0;
    for (int i = 0; i < N; i++) {
        if (H[i] >= h) {
            res++;
            h = H[i];
        }
    }
    cout << res << endl;
    return 0;
}