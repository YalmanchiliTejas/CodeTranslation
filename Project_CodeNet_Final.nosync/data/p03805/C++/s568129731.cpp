#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <climits>

using namespace std;

typedef long long ll;
typedef vector<int> ivec;
typedef pair<int, int> ipair;

int N, M;
bool ab[10][10];

int main() {
    int a, b;
    cin >> N >> M;
    memset(ab, 0, sizeof ab);
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        ab[a-1][b-1] = true;
        ab[b-1][a-1] = true;
    }

    ivec p(N);
    p[0] = 0;
    for (int i = 1; i < N; i++) {
        p[i] = i;
    }
    int count = 0;
    do {
        count++;
        for (int i = 0; i < N - 1; i++) {
            a = p[i];
            b = p[i+1];
            if (!ab[a][b]) {
                count--;
                break;
            }
        }
    } while (next_permutation(p.begin()+ 1, p.end()));

    cout << count << endl;

    return 0;
}
