#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> data;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        data.push_back(tmp);

    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < i; j++) {
            if (data[i] >= data[j]) {
                count++;
//                cout << "i = " << i << "j = " << j << endl;
            }
        }
        if (count == i) {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}