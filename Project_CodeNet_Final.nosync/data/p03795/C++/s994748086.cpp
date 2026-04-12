#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int sum = 0;
    for (int i = 1; i < N + 1; i++) {
        if (i % 15 == 0) {
            sum -= 200;
        }
        sum += 800;
    }
    cout << sum;
}