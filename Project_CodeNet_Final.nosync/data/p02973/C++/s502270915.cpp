#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    multiset<int> colors;
    for (auto a : A) {
        auto it = colors.lower_bound(a);
        if (it != colors.begin()) {
            --it;
            colors.erase(it);
        }
        colors.insert(a);
    }
    cout << colors.size() << endl;
    return 0;
}
