#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    deque<int> q;
    if(n & 1)
    {
        int tmp;
        for(int i = 0; i < n; ++i)
        {
            cin >> tmp;
            if(i % 2 ==1)
            q.push_back(tmp);
            else
            q.push_front(tmp);
        }
    }
    else
    {
        int tmp;
        for(int i = 0; i < n; ++i)
        {
            cin >> tmp;
            if(i % 2 == 0)
                q.push_back(tmp);
            else
                q.push_front(tmp);
        }
    }
    vector<int > a;
    while(!q.empty())
    {
        a.push_back(q.front());
        q.pop_front();
    }
    int sz = (int)a.size();
    for(int i = 0 ;i < sz ;++i)
    {
        if(i == sz - 1) cout << a[i] << endl;
        else cout << a[i] <<" ";
    }
    return 0;
}