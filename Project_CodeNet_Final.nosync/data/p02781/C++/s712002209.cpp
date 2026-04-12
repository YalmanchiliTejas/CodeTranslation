#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string N;
    int K;
    cin >> N >> K;
    int keta = N.size();
    vector<vector<vector<ll>>> dp(keta + 1, vector<vector<ll>>(2, vector<ll>(K + 1, 0)));//<左からN桁まで>、<境界は1、それ以外0>、<0以外の数>
    dp.at(1).at(1).at(1) = 1;
    dp.at(1).at(0).at(1) = N.at(0) - '0' - 1;
    for(int i = 2; i <= keta; i++)
    {
        dp.at(i - 1).at(0).at(0) = 1;
        int num = N.at(i - 1) - '0';
        for(int j = 1; j <= K; j++)
        {
            if(num > 0)
            {
                dp.at(i).at(1).at(j) = dp.at(i - 1).at(1).at(j - 1);
            } else {
                dp.at(i).at(1).at(j) = dp.at(i - 1).at(1).at(j);
            }
        }
        for(int j = 1; j <= K; j++)
        {
            //境界以外の桁が0の分
            dp.at(i).at(0).at(j) += dp.at(i - 1).at(0).at(j);
            //境界以外の桁が0以外の分
            dp.at(i).at(0).at(j) += dp.at(i - 1).at(0).at(j - 1) * 9;
            if(num > 0)
            {
                //境界の桁が0の分(numが0の時は境界の方に追加されているので追加しない)
                dp.at(i).at(0).at(j) += dp.at(i - 1).at(1).at(j);
                //境界の桁が0以外の分(境界の方を除くため-1)
                dp.at(i).at(0).at(j) += dp.at(i - 1).at(1).at(j - 1) * (num - 1);
            }
            
        }
    }
    ll answer = dp.at(keta).at(1).at(K) + dp.at(keta).at(0).at(K);
    cout << answer << endl;
    return 0;
}
