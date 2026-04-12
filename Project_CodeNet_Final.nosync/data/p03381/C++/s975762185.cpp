#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> nums(N);
    vector<ll> sortNums(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nums.at(i);
    }
    copy(nums.begin(), nums.end(), sortNums.begin());
    sort(sortNums.begin(), sortNums.end());
    ll median = sortNums.at(N / 2 - 1);
    for (int i = 0; i < N; i++)
    {
        cout << ((nums.at(i) > median) ? sortNums.at(N / 2 - 1) : sortNums.at(N / 2)) << "\n";
    }
    cout.flush();
    return 0;
}
