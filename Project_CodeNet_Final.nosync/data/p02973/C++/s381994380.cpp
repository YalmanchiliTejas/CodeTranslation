#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define PRINT(x) cout<<(x)<<endl
#define INF 1000000000000 // 10^12
#define MOD 1000000007 // 10^9+7
#define PB push_back
#define MP make_pair

const int MAX_N = 100000;

int N;
int A[MAX_N];

int last_num[MAX_N + 1];
int num_color = 0;

int my_binary_search(int key) {
    int ng = -1;
    int ok = num_color;
    while (abs(ng - ok) > 1) {
        int mid = (ng + ok) / 2;
        if (last_num[mid] < key) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    cin >> N;
    REP(i, N) cin >> A[i];

    last_num[0] = MOD;

    REP(i, N) {
        if (A[i] <= last_num[num_color]) last_num[++num_color] = A[i];
        else {
            int j = my_binary_search(A[i]);
            last_num[j] = A[i];
        }
    }

    PRINT(num_color);
    return 0;
}