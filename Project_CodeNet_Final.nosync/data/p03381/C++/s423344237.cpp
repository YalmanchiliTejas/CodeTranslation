#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;
typedef vector<pair<int,int>> vii;
typedef vector<vector<int>> vvi;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int MAXN = 2e5+100;
int n;
int A[MAXN], B[MAXN], ans[MAXN];

int main (void) {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        B[i] = A[i];
    }

    if (n == 2) {
        cout << A[1] << "\n" << A[0] << endl;
        return 0;
    }

    int med[3];
    for (int i = 0; i < 3; i++) {
        sort(B, B+n-1);
        med[i] = B[(n-1)/2];
        swap(B[(n-1)/2], B[n-1]);
    }
    sort(med, med+3);

    ans[n-1] = med[1];
    int idx = 1;
    for (int i = n-2; i >= 0; i--) {
        if ((A[i] >= med[idx] && A[i+1] < med[idx])
                || (A[i] > med[idx] && A[i+1] <= med[idx])) {
            idx--;
        } else if ((A[i] <= med[idx] && A[i+1] > med[idx])
                || (A[i] < med[idx] && A[i+1] >= med[idx])) {
            idx++;
        }
        idx = max(0, min(idx, 2));
        ans[i] = med[idx];
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }


    return 0;
}
