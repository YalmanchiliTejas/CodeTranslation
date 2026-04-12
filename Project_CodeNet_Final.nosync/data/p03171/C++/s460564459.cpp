#include <iostream>
#include <fstream>

using namespace std;
int N;
long long d[3005][3005];
int a[3005];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = 1; i <= N; i++)
        d[i][i] = a[i];
    for (int k = 2; k <= N; k++)
        for (int i = 1; i <= N - k + 1; i++) {
            int j = i + k - 1;
            d[i][j] = max(a[i] - d[i + 1][j], a[j] - d[i][j - 1]);
        }
    cout << d[1][N];
}