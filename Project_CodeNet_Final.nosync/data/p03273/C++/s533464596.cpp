#include <bits/stdc++.h>

using namespace std;

string s[10010];

int a[1010],b[1010];

vector <string> v;

int main()
{
    int n,m;
    cin >> n >> m;

    memset(a,0,1010*sizeof(a[0]));

    for(int i=0;i<n;i++)
        cin >> s[i];

    for(int i=0;i<n;i++)
    {
        int count = 0;

        for(int j=0;j<m;j++)
        {
            if(s[i][j] == '#')
                count++;
        }

        if(count > 0)
            v.push_back(s[i]);
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(v[j][i] == '#')
                a[i] = 1;
        }
    }

    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[j] == 1)
                cout << v[i][j];
        }
        cout << endl;
    }
}