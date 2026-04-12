#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define SZ(a) ((int)a.size())
typedef long long ll;

int N, a;
deque<int> q;

int main () {
        cin >> N;
        fo(i, 0, N) {
                cin >> a;
                if (i&1) q.push_front(a);
                else q.push_back(a);
        }
        if (N&1) {
                while (q.size()) printf("%d ", q.back()), q.pop_back();
        } else {
                while (q.size()) printf("%d ", q.front()), q.pop_front();
        }
        return 0;
}
