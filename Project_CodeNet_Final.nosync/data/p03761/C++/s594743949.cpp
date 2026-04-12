#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> cnt(26, 50);
    int n;
    for (cin >> n; n--;)
    {
        string s;
        cin >> s;
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;
        
        for (int i = 0; i != 26; ++i)
            cnt[i] = min(cnt[i], count[i]);
    }
    
    for (int i = 0; i != 26; ++i)
        for (int j = 0; j != cnt[i]; ++j)
            cout << (char) ('a' + i);
    
    return 0;
}
