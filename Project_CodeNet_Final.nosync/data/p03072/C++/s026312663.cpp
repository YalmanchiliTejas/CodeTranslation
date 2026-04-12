#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> hs = vector<int>(n);
    cin >> hs[0];
    int maxH = 0;
    int c = 1;
    for (int i = 1; i < n; i++) {
        cin >> hs[i];
        if (hs[maxH] <= hs[i]) {
            c++;
        }
        if (hs[maxH] < hs[i]){
            maxH = i;
        }
    }
    cout << c << endl;

    return 0;
}