#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &a : A) cin >> a;
    vector<int> Bp, Binv;
    reverse(A.begin(), A.end());
    for (auto a : A) {
        (Bp.size() == Binv.size() ? Bp : Binv).push_back(a);
    }
    reverse(Binv.begin(), Binv.end());
    Bp.insert(Bp.end(), Binv.begin(), Binv.end());
    for (auto b : Bp) printf("%d ", b);
    puts("");
}
