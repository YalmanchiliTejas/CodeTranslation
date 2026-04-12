#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s[n];
    for(int i = 0;i < n;i++)
    {
        cin >> s[i];
    }
    vector<int> v;
    for(int i = 0;i < 26;i++)
    {
        char c = 'a' + i;
        int c_count = 0;
        for(int x = 0;x < s[0].size();x++)
        {
            if(s[0][x] == c)
            {
                c_count++;
            }
        }
        bool flag = true;
        for(int j = 0;j < n;j++)
        {
            int count = 0;
            for(int k = 0;k < s[j].size();k++)
            {
                if(s[j][k] == c)
                {
                    count++;
                }
            }
            if(count < c_count)
            {
                c_count = count;
            }
        }
        v.push_back(c_count);
    }
    for(int i = 0;i < 26;i++)
    {
        char c = 'a' + i;
        for(int j = 0;j < v.at(i);j++)
        {
            cout << c;
        }
    }
    cout << "\n";

    return 0;
}