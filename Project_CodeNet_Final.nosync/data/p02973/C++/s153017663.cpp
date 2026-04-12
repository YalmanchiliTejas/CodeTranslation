#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<ll, ll> p;
 
#define MOD 1000000007
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> A(N);

    for(int i = 0; i < N; i++) cin >> A[i];

    vector<int> v;
    v.push_back(A[A.size() - 1]);

    for(int i = A.size() - 2; i >= 0; i--) {
        int a = A[i];
        if(a >= v[v.size() - 1]) {
            v.push_back(a);
        } else {
            int x = upper_bound(v.begin(), v.end(), a) - v.begin();
            v[x] = a;
        }
    }

    cout << v.size() << endl;
}