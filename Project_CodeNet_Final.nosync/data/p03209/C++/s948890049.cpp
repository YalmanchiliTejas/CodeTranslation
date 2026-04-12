#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N, X;
    cin >> N >>X;
    ll countSum[N + 1];
    ll countPatty[N + 1];
    // B L(n-1) P L(n-1) B で区切ってバーガーの層数とパティをカウント
    map<int, vector<pair<ll, ll>>> countBurger;
    countSum[0] = 1;
    countPatty[0] = 1;
    countBurger[0].push_back(make_pair(1, 1));
    for (int i = 1; i <= N; ++i)
    {
        countSum[i] = 2 * countSum[i - 1] + 3;
        countPatty[i] = 2 * countPatty[i - 1] + 1;
        countBurger[i].push_back(make_pair(1, 0));
        countBurger[i].push_back(make_pair(countSum[i -1], countPatty[i - 1]));
        countBurger[i].push_back(make_pair(1, 1));
        countBurger[i].push_back(make_pair(countSum[i -1], countPatty[i - 1]));
        countBurger[i].push_back(make_pair(1, 0));
    }

    ll currentIndex = 0;
    ll ans = 0;
    bool isEnd = false;
    for (int i = N; i >= 0; --i)
    {
        for (auto iter = countBurger[i].begin(); iter != countBurger[i].end(); ++iter)
        {
            if (currentIndex  + (*iter).first < X)
            {
                currentIndex += (*iter).first;
                ans += (*iter).second;
            }
            else if (currentIndex  + (*iter).first > X)
            {
                break;
            }
            else
            {
                isEnd = true;
                currentIndex += (*iter).first;
                ans += (*iter).second;
                break;
            }
        }
        if (isEnd) break;
    }

    cout << ans << endl;
}
