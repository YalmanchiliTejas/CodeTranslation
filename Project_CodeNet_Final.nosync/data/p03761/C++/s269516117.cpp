#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define inf 1000000100

int main()
{
    int n;
    cin >> n;
    map<char ,int> mp;
    while(n--)
    {
        string str;
        cin >> str;
        vi alpha(26);
        for(int i = 0; str[i]; i++)
        {
            alpha[str[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++)
        {
            if(mp.count((char)('a'+i)))
            {
                mp[(char)('a'+i)] = min(mp[(char)('a'+i)], alpha[i]);
            }
            else
            {
                mp[(char)('a'+i)] = alpha[i];
            }
        }

    }
    
        for(int i = 0; i < 26; i++)
        {
            if(mp.count((char)('a'+i)))
            {
                for(int j = 0; j < mp[(char)('a'+i)]; j++)
                {
                    cout << (char)('a'+i);
                }
            }
        }
        cout << endl;


}
