#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
    ios_base::sync_with_stdio(false);
    lli n;
    cin >> n;

    vector<lli> v(n);
    lli total_sum = 0;

    for(lli i = 0; i < n; i++)
    {
        cin >> v[i];
        total_sum += v[i];
    }

    lli current_sum = 0;
    lli answer = 0;

    for(int i = 0; i < n; i++)
    {
        current_sum += v[i];
        lli factor = total_sum - current_sum;
        factor = factor%(1000000000 + 7);

        answer += v[i]*factor;
        answer = answer%(1000000000 + 7);

    }

    cout << answer << endl;

}

