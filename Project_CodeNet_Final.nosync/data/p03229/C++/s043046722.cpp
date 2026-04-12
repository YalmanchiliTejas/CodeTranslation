#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>
using namespace std;


int main(void) {
    int n; cin >> n;
    vector<int> as;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        as.push_back(a);
    }

    sort(as.begin(), as.end());
    
    if (n % 2 == 0) {
        int uppermin = as[n / 2];
        int lowermax = as[n / 2 - 1];
        long long uppersum = 0;
        long long lowersum = 0;
        for (int i = 0; i < n / 2; i++) {
            uppersum += as[n / 2 + i];
            lowersum += as[i];
        }
        cout << 2 * uppersum - uppermin - 2 * lowersum + lowermax << endl; 
    }
    else {
        long long res;
        long long uppersum = 0;
        long long lowersum = 0;
        for  (int i = 0; i < n / 2; i++) {
            uppersum += as[n / 2 + i];
            lowersum += as[i];
        }
        uppersum += as[n - 1];
        
        //cout << uppersum << endl;
        //cout << lowersum << endl;

        res = 2 * uppersum - 2 * lowersum - as[n / 2] - as[n / 2 + 1];

        uppersum -= as[n / 2];
        lowersum += as[n / 2];

        //cout << uppersum << endl;
        //cout << lowersum << endl;

        res = max(res, 2 * uppersum - 2 * lowersum + as[n / 2] + as[n / 2 - 1]);
        cout << res << endl;
    }
    return 0;
}