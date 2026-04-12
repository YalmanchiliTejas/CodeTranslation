#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int i, j=0, n, p[200][200];
    while(cin >> n && n){
        for(i=0; i<n; i++) cin >> p[j][i];
        sort(p[j], p[j]+n);
        cout << accumulate(p[j]+1, p[j]+n-1, 0) / (n-2) << endl;
        j++;
    }
}
