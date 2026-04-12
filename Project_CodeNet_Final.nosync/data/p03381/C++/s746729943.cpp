#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <cmath>
#include <string>

using namespace std;

int main(void) {
    vector<int> x,s;
    int n,t;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> t;
        x.push_back(t);
        s.push_back(t);
    }
    sort(s.begin(),s.end());
    for(int i = 0; i < n;i++) {
        if(x[i] <= s[n/2-1])
            cout << s[n/2] << endl;
        else
            cout << s[n/2-1] << endl;
    }
    return 0;
}
