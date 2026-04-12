#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <queue>
#include <set>

using namespace std;

int main () {
    int N, M;
    cin>>N>>M;
    vector<int> v(N);
    for (int i = 0; i < N; i++) v[i] = i+1;
    set<pair<int,int>> e;
    for (int i = 0; i < M; i++) {
        int a,b;
        cin>>a>>b;
        e.insert(make_pair(a,b));
        e.insert(make_pair(b,a));
    }

    int count = 0;
    do {
        bool flag = true;
        for (int i = 0; i < N-1; i++) {
            if (e.count(make_pair(v[i], v[i+1])) == 0) {
                flag = false;
                break;
            }
        }
        if (flag) count++;
    } while (next_permutation(begin(v)+1, end(v)));

    cout<<count<<endl;

    return 0;
}