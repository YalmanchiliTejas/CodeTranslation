#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> u(N); for (int i=0; i<N; ++i) cin >> u[i];  // 昇順
    sort(u.begin(), u.end());

    if (N % 2 != 0) {
        ll sump1 = 0, sump2 = 0, sumn1 = 0, sumn2 = 0;
        sump1 += u[N/2] + u[N/2 + 1];
        for (int i = N/2 + 2; i < N; ++i) {
            sump1 += 2 * u[i];
        }
        for (int i = 0; i < N/2; ++i) {
            sumn1 += 2 * u[i];
        }
        
        for (int i = N/2 + 1; i < N; ++i) {
            sump2 += 2 * u[i];
        }
        sumn2 += u[N/2] + u[N/2 - 1];
        for (int i = 0; i < N/2 - 1; ++i) {
            sumn2 += 2 * u[i];
        }

        cout << max(sump1 - sumn1, sump2 - sumn2) << endl;
    } else {
        ll sump = 0, sumn = 0;
        sump += u[N/2];
        for (int i = N/2 + 1; i < N; ++i) {
            sump += 2 * u[i];
        }
        sumn += u[N/2-1];
        for (int i = 0; i < N/2 - 1; ++i) {
            sumn += 2 * u[i];
        }

        cout << max(sump - sumn, sumn - sump) << endl;
    }
}