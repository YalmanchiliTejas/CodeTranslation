#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> b;

    vector<int> ev;
    vector<int> od;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (i % 2 == 0) {
            ev.push_back(a);
        } else {
            od.push_back(a);
        }
    }


    if (n % 2 != 0) {
        for (int i = ev.size() - 1; i >= 0; i--) {
            cout << ev[i] << " ";
        }
        for (int i = 0; i < od.size(); i++) {
            cout << od[i] << " ";
        }
    } else {
        for (int i = od.size() - 1; i >= 0; i--) {
            cout << od[i] << " ";
        }
        for (int i = 0; i < ev.size(); i++) {
            cout << ev[i] << " ";
        }
    }
    cout << endl;
}
