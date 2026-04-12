#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <climits>
#include <map>
#include <functional>
#include <cmath>
#include <cassert>
#include <set>
#include <deque>

using namespace std;

vector<int> longest_decreasing_subsequence(const vector<int>& X)
{
    int N = X.size();
    vector<int> P(N);
    vector<int> M(N+1);

    int L = 0;
    for (int i = 0; i < N; i++) {
        // Binary search for the largest positive j ≤ L
        // such that X[M[j]] <= X[i]
        int lo = 1;
        int hi = L;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            if (X[M[mid]] >= X[i])
                lo = mid+1;
            else
                hi = mid-1;
        }

        // After searching, lo is 1 greater than the
        // length of the longest prefix of X[i]
        int newL = lo;

        // The predecessor of X[i] is the last index of 
        // the subsequence of length newL-1
        P[i] = M[newL-1];
        M[newL] = i;

        if (newL > L)
            // If we found a subsequence longer than any we've
            // found yet, update L
            L = newL;
    }

    // Reconstruct the longest decreasing subsequence
    vector<int> S(L);
    int k = M[L];
    for (int i = L-1; i >= 0; i--) {
        S[i] = X[k];
        k = P[k];
    }

    return S;
}

template<typename T>inline T get(){T x;cin>>x;return x;}

int main()
{
    int n = get<int>();
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = get<int>();

    auto b = longest_decreasing_subsequence(a);
    cout << b.size() << endl;
}
