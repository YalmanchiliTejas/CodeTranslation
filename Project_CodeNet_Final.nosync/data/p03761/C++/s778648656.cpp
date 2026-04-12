#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<string> S;
    S.resize(n);
    int cnttmp[26] = {};
    int cnt[26];
    fill(cnt, cnt + 26, INT_MAX);
    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
        for (char c : S[i])
        {
            cnttmp[c - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] > cnttmp[i]) cnt[i] = cnttmp[i];
        }
        fill(cnttmp, cnttmp + 26, 0);
        
    }

    char c = 'a';
    for (int m : cnt)
    {
        while (m > 0)
        {
            cout << c;
            m--;
        }
        c++;
        
    }
    
    cout << endl;
    
    return 0;
}