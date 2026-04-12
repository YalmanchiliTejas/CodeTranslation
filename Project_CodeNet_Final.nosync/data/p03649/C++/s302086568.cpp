#include <iostream>

using namespace std;
typedef long long ll;

const ll INF = 1e18;

int N;
ll a[55];

int main() {
        cin >> N;
        for (int i=0; i<N; i++)
                cin >> a[i];

        ll minK = INF;
        for (int K=0; K<=N; K++) {
                ll dk = 0;
                for (int i=0; i<N; i++)
                        dk += (a[i]+K+1)/(N+1);

                if (dk >= K)
                        minK = min(minK, K+(dk-K)*(N+1));
        }

        cout << minK << "\n";
}