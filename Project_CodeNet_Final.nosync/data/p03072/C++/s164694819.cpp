#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }

    int count = 1;
    for (int i = 1; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < i; j++) {
            if (vec.at(j) > vec.at(i)) flag = false;
        }

        if (flag) count++;
    }

    cout << count << endl;
    return 0;
}
