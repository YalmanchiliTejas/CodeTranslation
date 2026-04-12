// ABC058
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> count(26);
    vector<int> minCount(26, 100);

    rep(i, n)
    {
        string s;
        cin >> s;

        count.assign(count.size(), 0);

        rep(j, s.size()) count[s[j] - 'a']++;

        rep(j, 26) minCount[j] = min(minCount[j], count[j]);
    }

    rep(i, 26)
    {
        while (minCount[i] > 0)
        {
            cout << char('a'+i);
            minCount[i]--;
        }        
    }
    cout << endl;

    return 0;
}
