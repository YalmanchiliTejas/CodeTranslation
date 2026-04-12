#include <bits/stdc++.h>
using namespace std;

#define times(n, i)      uptil(0, n, i)
#define rtimes(n, i)     downto((n) - 1, 0, i)
#define upto(f, t, i)    for(int _##i = (t), i = (f); i <= _##i; i++)
#define uptil(f, t, i)   for(int _##i = (t), i = (f); i <  _##i; i++)
#define downto(f, t, i)  for(int _##i = (t), i = (f); i >= _##i; i--)
#define downtil(f, t, i) for(int _##i = (t), i = (f); i >  _##i; i--)
typedef long double ld;
#define long long long

#if defined(EBUG) && !defined(ONLINE_JUDGE)
    #define debug true
    #define ln << endl
#else
    #define debug false
    #define ln << '\n'
#endif
#define tb << '\t'
#define sp << ' '

const int MOD = 1e9+7;

int N, parent[100009], ssize[100009];
vector<int> paths[100009];

int parentDFS(int i, int p) {
    parent[i] = p;
    int s = 1;
    for(int j: paths[i]) if(j != p) s += parentDFS(j, i);
    return ssize[i] = s;
}

bool checkDFS(int i) {
    int c = 0;
    for(int j: paths[i]) {
        int k = j == parent[i] ? N - ssize[i] : ssize[j];
        c += k % 2;
    }
    if(c != 1) return true;
    for(int j: paths[i]) if(j != parent[i]) {
        if(checkDFS(j)) return true;
    }
    return false;
}

signed main() { // long: 64bit
    if(!debug) {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }

    scanf("%d",&N);
    times(N-1, i) {
        int A, B;
        scanf("%d%d",&A,&B);
        paths[A-1].push_back(B-1);
        paths[B-1].push_back(A-1);
    }

    parentDFS(0, 0);
    if(checkDFS(0)) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }

    return 0;
}
