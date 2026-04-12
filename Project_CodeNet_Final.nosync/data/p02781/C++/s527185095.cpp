#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int Cin()
{
    int n;
    cin >> n;
    return n;
}

int main()
{
    string N;
    int K;
    cin >> N >> K;
    LLONG digit = N.length();
    vector<LLONG> nums(digit);
    for (int i = 0; i < digit; ++i)
    {
        nums[i] = N[i] - '0';
    }
    LLONG ans = 0;
    if (K == 1)
    {
        // topに数字を入れるときと，top以外に数字を入れるとき
        ans = nums[0] + 9 * (digit - 1);
    }
    else if (K == 2 && digit >= 2)
    {
        // topに数字を入れるとき
        // top未満の数字をtopにおくとき
        ans += (nums[0] - 1LL) * 9LL * (digit - 1LL);
        // topにtopの数字をおくとき，初めてゼロ以外になる場所を探す
        int nonZero = 0;
        for (int i = 1; i < digit; ++i)
        {
            if (nums[i] != 0)
            {
                nonZero = i; break;
            }
        }
        if (nonZero > 0)
        {
            ans += nums[nonZero] + 9LL * (digit - 1LL - nonZero);
        }

        // topに数字をおかないとき
        if (digit > 2)
        {
            ans += 81LL * (digit - 1LL) * (digit - 2LL) / 2LL;
        }
    }
    else if (K == 3 && digit >= 3)
    {
        // topに数字を入れるとき
        // top未満の数字をtopにおくとき
        ans += (nums[0] - 1) * 81LL * (digit - 1LL) * (digit - 2LL) / 2LL;
        // topにtopの数字をおくとき，初めてゼロ以外になる場所を探す
        int nonZero = 0;
        for (int i = 1; i < digit; ++i)
        {
            if (nums[i] != 0)
            {
                nonZero = i; break;
            }
        }
        // noneZeroの位置を含めて２桁以上残っていなければならない
        if (nonZero > 0 && digit - nonZero >= 2)
        {
            // nonZeroの位置に数字をおく場合
            // nonZeroにnonZeroの値をおく場合，次にゼロ以外になる場所を探す
            int nonZero2 = 0;
            for (int i = nonZero + 1; i < digit; ++i)
            {
                if (nums[i] != 0)
                {
                    nonZero2 = i; break;
                }
            }
            if (nonZero2 != 0)
            {
                ans += nums[nonZero2] + 9LL * (digit - nonZero2 - 1LL);
            }

            // nonZeroにnonZero未満の値をおく場合
            ans += (nums[nonZero] - 1LL) * 9LL * (digit - 1LL - nonZero);
            
            // nonZeroの位置より下の桁に数字を置く場合
            if (digit - 1 - nonZero >= 2)
            {
                ans += 81LL * (digit - 1LL - nonZero) * (digit - 2LL - nonZero) / 2LL;
            }
        }

        // topに数字をおかないとき
        if (digit > 3)
        {
            ans += 729LL * (digit - 1LL) * (digit - 2LL) * (digit - 3LL) / 6LL;
        }
    }
    cout << ans << endl;
}
