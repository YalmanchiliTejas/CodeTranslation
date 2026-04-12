#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int N; cin >> N;
    vector<int> a;
    for (int i = 0; i < N; ++i) {
        int aa; cin >> aa;
        a.push_back(aa);
    }

    multiset<long long> se;
    for (auto ai : a) {
        se.insert(ai);
        if (se.size() >= 2 and ai > *begin(se)){
            se.erase(--se.lower_bound(ai));
            }
//    cout << se.size() << endl;
        
    }
    cout << se.size() << endl;
}
