#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long ll;
const int MAXN = 0;

int main()
{
	//freopen("input.in", "r", stdin);
    string s;
    cin >> s;
    for (int i = 0; i < s.length()-1; i++)
    {
        if (s[i] == 'A' && s[i+1] == 'C')
        {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
	return 0;
}
