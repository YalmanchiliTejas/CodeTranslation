#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int array[200005];
    vector<int> front, back;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> array[i];
    }

    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            front.push_back(array[i]);
        } else {
            back.push_back(array[i]);
        }
    }

    if (n & 1) {
        for (int i = front.size() - 1; i >= 0; i--) {
            cout << front[i];
            if (i) {
                cout << " ";
            }
        }

        for (int i = 0; i < back.size(); i++) {
            cout << " ";
            cout << back[i];
        }
                         
    } else {

        for (int i = back.size() - 1; i >= 0; i--) {
            cout << back[i];

            if (i) {
                cout << " ";
            }
        }

        for (int i = 0; i < front.size(); i++) {
            cout << " ";
            cout << front[i];
        }
    }
    cout << endl;

    return 0;
}
