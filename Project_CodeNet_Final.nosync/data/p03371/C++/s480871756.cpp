#include <bits/stdc++.h>
using namespace std;

void main_()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    vector<int> costs;
    for (int ab_num = 0; ab_num <= 2 * 100000; ab_num += 2) {
        int a_num = max((X - ab_num / 2), 0);
        int b_num = max((Y - ab_num / 2), 0);
        int cost = a_num * A + b_num * B + ab_num * C;
        costs.push_back(cost);
    }

    cout << *min_element(begin(costs), end(costs)) << endl;
}
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    main_();
    return 0;
}
