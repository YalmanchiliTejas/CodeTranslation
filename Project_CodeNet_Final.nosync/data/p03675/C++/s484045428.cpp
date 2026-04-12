#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;
    vector< int > a(1000000);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector< int > b;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) b.push_back(a[i]);
        else           b.insert(b.begin(), a[i]);
    }

    if(n % 2) {
        for(auto p = b.rbegin(); p != b.rend(); p++) {
            cout << *p << (p == b.rend() - 1 ? '\n' : ' ');
        }
    } else {
        for(auto p = b.begin(); p != b.end(); p++) {
            cout << *p << (p == b.end() - 1 ? '\n' : ' ');
        }
    }
}
