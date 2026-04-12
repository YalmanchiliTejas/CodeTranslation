#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <ctime>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define fs first
#define sc second
#define INF 1000000000
#define MOD 1000000007
#define EPS 0.00000001


int main() {
    int N; cin >> N;
    int ans = 0;
    vector<int> H(N);
    for(int &h:H)
        cin >> h;
    for(int i=0; i<N; i++){
        bool f = true;
        for(int j=0; j<i; j++){
            if(H[j] > H[i]) f = false;
        }
        if(f) ans++;
    }
    cout << ans << endl;
}
