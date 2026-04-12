#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int mount[N];
    for (int i = 0; i < N; i++) {
        cin >> mount[i];
    }

    int count = 1;
    for (int i = 1; i < N; i++) {
        bool flag = true;
        for (int j = 0; j < i; j++) {
            if (mount[i] < mount[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}