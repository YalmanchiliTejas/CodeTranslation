#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n,m;
    cin >> n >> m;
    vector< pair<int,int> > v;
    for (int i=0;n>i;i++)
    {
        for (int j=0;m>j;j++)
        {
            char c;
            cin >> c;
            if (c == '#') v.push_back(make_pair(i,j));
        }
    }
    for (pair<int,int> p:v)
    {
        for (pair<int,int> q:v)
        {
            if (p.first < q.first && p.second > q.second)
            {
                puts("Impossible");
                return 0;
            }
        }
    }
    puts("Possible");
}
