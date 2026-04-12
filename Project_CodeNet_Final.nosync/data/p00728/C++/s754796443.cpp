#include<iostream>
using namespace std;

int N, S;
int main() {
    while(cin >> N && N > 0) {
        int sum = 0;
        int maxi=0, mini=1000000;
        for (int i=0; i<N; ++i) {
            cin >> S;
            sum += S;
            if (S > maxi) {
                maxi = S;
            }
            if (S < mini) {
                mini = S;
            }
        }
        double ans = (sum - maxi - mini) / (N - 2);
        cout << ans << endl;
    }
}
