#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

vector<int> p;
vector<int> a[10];
vector<int> used(10);

int main() {
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        p.push_back(i);
    ll answ = 0;
    do
    {
        if (p[0] != 1) break;
        bool f = true;
        for (int i = 0; i < p.size()-1; i++)
        {
            bool f1 = false;
            for (auto j = a[p[i]].begin(); j != a[p[i]].end(); j++)
                if (*j == p[i+1]) f1 = true;
            if (!f1) {f = false; break;}
        }
        if (f) answ++;
    }while (next_permutation(p.begin(),p.end()));
        cout << answ << endl;
    return 0;
}