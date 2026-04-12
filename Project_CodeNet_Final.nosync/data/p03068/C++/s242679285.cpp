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
    string S; cin >> S;
    int K; cin >> K;
    
    char c = S[K-1];
    for(int i=0; i<N; i++){
        if(S[i]!=c) S[i] = '*';
    }
    cout << S << endl;
    return 0;
}
