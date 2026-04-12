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
    string s;
    cin >> s;
    string ans(n, '*');
    queue<string> q;
    if(s[0] == 'x')
    {
        ans[0] = 'S';
        ans[1] = 'W';
        ans[n-1] = 'S';
        q.push(ans);
        ans[0] = 'S';
        ans[1] = 'S';
        ans[n-1] = 'W';
        q.push(ans);
        ans[0] = 'W';
        ans[1] = 'S';
        ans[n-1] = 'S';
        q.push(ans);
        ans[0] = 'W';
        ans[1] = 'W';
        ans[n-1] = 'W';
        q.push(ans);
    }
    else if (s[0] == 'o')
    {
        ans[0] = 'S';
        ans[1] = 'S';
        ans[n-1] = 'S';
        q.push(ans);
        ans[0] = 'S';
        ans[1] = 'W';
        ans[n-1] = 'W';
        q.push(ans);
        ans[0] = 'W';
        ans[1] = 'S';
        ans[n-1] = 'W';
        q.push(ans);
        ans[0] = 'W';
        ans[1] = 'W';
        ans[n-1] = 'S';
        q.push(ans);
    }
    bool solve = 0;
    while(!q.empty())
    {
        string t = q.front();
        q.pop();
        for(int i = 1; i < n-1; i++)
        {
            if(i == n-2)
            {
                char c;
                if(s[i] == 'x')
                {
                    if(t[i] == 'W')
                    {
                        c = (t[i-1] == 'S') ? 'S' : 'W';
                    }
                    else if (t[i] == 'S')
                    {
                        c = (t[i-1] == 'S') ? 'W' : 'S';
                    }
                }
                else if(s[i] == 'o')
                {
                    if(t[i] == 'W')
                    {
                        c = (t[i-1] == 'S') ? 'W' : 'S';
                    }
                    else if (t[i] == 'S')
                    {
                        c = (t[i-1] == 'S') ? 'S' : 'W';
                    }
                }

                if(c == t[i+1])
                {
                    solve = 1;
                    ans = t;
                    break;
                }
            }

            if(s[i] == 'x')
            {
                if(t[i] == 'W')
                {
                    t[i+1] = (t[i-1] == 'S') ? 'S' : 'W';
                }
                else if (t[i] == 'S')
                {
                    t[i+1] = (t[i-1] == 'S') ? 'W' : 'S';
                }
            }

            else if(s[i] == 'o')
            {
                if(t[i] == 'W')
                {
                    t[i+1] = (t[i-1] == 'S') ? 'W' : 'S';
                }
                else if (t[i] == 'S')
                {
                    t[i+1] = (t[i-1] == 'S') ? 'S' : 'W';
                }
            }
        }
        char c;
        if(s[n-1] == 'o')
        {
            if(t[n-1] == 'W')
            {
                c = (t[n-2] == 'S') ? 'W' : 'S';
            }
            else if(t[n-1] == 'S')
            {
                c = (t[n-2] == 'S') ? 'S' : 'W';
            }
        }
        else if (s[n-1] == 'x')
        {
            if(t[n-1] == 'W')
            {
                c = (t[n-2] == 'S') ? 'S' : 'W';
            }
            else if(t[n-1] == 'S')
            {
                c = (t[n-2] == 'S') ? 'W' : 'S';
            }
        }

        if(t[0] != c)
        {
            solve = 0;
        }

        if(solve)
        {
            break;
        }
    }

    if(solve)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}
