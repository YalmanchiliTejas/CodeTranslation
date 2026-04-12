#include <iostream>
#include <vector>
using namespace std;
vector<int> v[9]; int N, M;
struct Node {
    int now = 1; int cnt[9] = {1,1,0};
};
int next(Node n) {
    if(n.cnt[n.now] > 1) return 0;
    if(n.cnt[0] == N) return 1;
    int root = 0;
    for(int x : v[n.now]) {
        if(n.cnt[x] == 1) continue;
        Node n2 = n;
        n2.cnt[n.now] += 1; n2.cnt[0] += 1; n2.now = x;
        root += next(n2);
    }
    return root;
}
int main() {
    cin >> N >> M;
    for(int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    Node n;
    cout << next(n);
}