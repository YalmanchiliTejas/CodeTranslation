#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int n, a;
list<int> b;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (i % 2 == 0) {
            b.push_back(a);
        }
        else {
            b.push_front(a);
        }
    }

    if (n % 2 != 0) {
        reverse(b.begin(), b.end());
    }

    list<int>::iterator itr;
    for (itr = b.begin(); itr != b.end(); itr++) {
        cout << *itr << " ";
    }

    cout << endl;
}
