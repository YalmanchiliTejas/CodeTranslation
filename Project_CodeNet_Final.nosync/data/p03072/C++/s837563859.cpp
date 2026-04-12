#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    int count = 0;
    for ( int i = 0; i < n; i++) {
        cin >> h.at(i);
    }
    int maxint;
    for (int i = 0; i < n; i++) {
        maxint = 0;
        for (int j = 0; j <= i; j++) {
            maxint = max(maxint, h.at(j));
        }
        if (maxint <= h.at(i)) count++;
    }
    cout << count << endl;
}
