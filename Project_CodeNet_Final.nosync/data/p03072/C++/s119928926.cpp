#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i=0; i<N; i++) {
        cin >> H[i];
    }
    
    int ans=0;
    int max=0;
    for (int i=0; i<N; i++) {
        if (H[i]>=max) {
            ans++;
            max=H[i];
        }
    }
    
    cout << ans << endl;
}
