#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main () {

    int n;
    cin >> n;
    
    vector<int> h;
    for (int i = 0; i < n; ++i) {
        int a=0;
        cin >> a;
        h.push_back(a);
    }

    int nCnt = 1;
    for (int i = 1; i < n; ++i) {
        bool low = false;
        for (int j=0; j < i; ++j) {
            if (h[i] < h[j]) {
                low = true;
                break;
            }
        }

        if (!low) nCnt++;
    }

    cout << nCnt << endl;
    return 0;
}