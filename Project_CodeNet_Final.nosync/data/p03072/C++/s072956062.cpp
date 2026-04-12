#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define pi 3.141592653589793
using namespace std;


bool prime[100000];
vector<ll> primes;
void sieve() {
    fill(prime, prime + 100000, 1);
    prime[0] = prime[1] = 0;

    for (int i = 2; i < 100000; i++) {
        if (prime[i]) {
            primes.pb(i);
            for (int j = i * 2; j < 100000; j += i) {
                prime[j] = 0;
            }
        }
    }
}



int main() {
    cout << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int e;
    cin >> e;
    int m = e;
    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
        cin >> e;
        if (m <= e) {
            ans++;
        }
        m = max(m, e);
    }

    cout << ans;


}




