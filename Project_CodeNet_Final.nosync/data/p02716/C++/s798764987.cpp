#include<bits/stdc++.h>
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

int main(int, char**)
{
    int n;
    cin >> n;

    // 偶数はi/2個かi/2-1個の選び方しかありえない
    // 奇数はi/2+1個かi/2個の選び方しかありえない
    vector<ll> max_choice(n+1,0);   // 偶数からi/2個 or 奇数からi/2+1個 選んだ場合の総和の最大値
    vector<ll> min_choice(n+1,0);   // 偶数からi/2-1個 or 奇数からi/2個 選んだ場合の総和の最大値

    ll tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        if (i == 1) {
            max_choice[i] = tmp;
            min_choice[i] = 0;
        } else if (i == 2) {
            max_choice[i] = max(max_choice[i-1], tmp);
            min_choice[i] = 0;
        } else if (i % 2 == 0) {
            max_choice[i] = max(max_choice[i-1], max_choice[i-2] + tmp);
            min_choice[i] = max(min_choice[i-1], min_choice[i-2] + tmp);
        } else {
            max_choice[i] = max_choice[i-2] + tmp;
            min_choice[i] = max(max_choice[i-1], min_choice[i-2] + tmp);
        }
    }

    if (n % 2 == 0)
        cout << max_choice[n] << endl;
    else
        cout << min_choice[n] << endl;

    return 0;
}