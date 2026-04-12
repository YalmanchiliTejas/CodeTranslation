#include <bits/stdc++.h>
using namespace std;

/* define const */

/* finish defineing const */

int n;
string s;
char animal[100010];

void init_animal()
{
    for (int i = 0; i < n; i++)
    {
        animal[i] = 0;
    }
}

void print_anm()
{
    for (int i = 0; i < n; i++)
    {
        cout << animal[i];
    }
    cout << endl;
    exit(0);
}

bool check_n()
{
    // s[n-2], s[n-1], s[0]の整合性チェック
    if (animal[n - 2] == animal[0])
    {
        if (animal[n - 1] == 'S' && s[n - 1] == 'o')
        {
            return true;
        }
        else if (animal[n - 1] == 'W' && s[n - 1] == 'x')
        {
            return true;
        }
    }
    else if (animal[n - 2] != animal[0])
    {
        if (animal[n - 1] == 'S' && s[n - 1] == 'x')
        {
            return true;
        }
        else if (animal[n - 1] == 'W' && s[n - 1] == 'o')
        {
            return true;
        }
    }
    return false;
}

bool check_0()
{
    // s[n-1], s[0], s[1]の整合性チェック
    if (animal[n - 1] == animal[1])
    {
        if (animal[0] == 'S' && s[0] == 'o')
        {
            return true;
        }
        else if (animal[0] == 'W' && s[0] == 'x')
        {
            return true;
        }
    }
    else if (animal[n - 1] != animal[1])
    {
        if (animal[0] == 'S' && s[0] == 'x')
        {
            return true;
        }
        else if (animal[0] == 'W' && s[0] == 'o')
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n;
    cin >> s;
    // input

    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            init_animal();
            (i == 0) ? (animal[0] = 'S') : (animal[0] = 'W');
            (j == 0) ? (animal[1] = 'S') : (animal[1] = 'W');
            for (int k = 2; k < n; k++)
            {
                if (animal[k - 2] == 'S' && animal[k - 1] == 'S')
                {
                    if (s[k - 1] == 'o')
                    {
                        animal[k] = 'S';
                    }
                    else if (s[k - 1] == 'x')
                    {
                        animal[k] = 'W';
                    }
                    else
                    {
                        cout << "err2" << endl;
                    }
                }
                else if (animal[k - 2] == 'S' && animal[k - 1] == 'W')
                {
                    if (s[k - 1] == 'o')
                    {
                        animal[k] = 'W';
                    }
                    else if (s[k - 1] == 'x')
                    {
                        animal[k] = 'S';
                    }
                    else
                    {
                        cout << "err2" << endl;
                    }
                }
                else if (animal[k - 2] == 'W' && animal[k - 1] == 'S')
                {
                    if (s[k - 1] == 'o')
                    {
                        animal[k] = 'W';
                    }
                    else if (s[k - 1] == 'x')
                    {
                        animal[k] = 'S';
                    }
                    else
                    {
                        cout << "err2" << endl;
                    }
                }
                else if (animal[k - 2] == 'W' && animal[k - 1] == 'W')
                {
                    if (s[k - 1] == 'o')
                    {
                        animal[k] = 'S';
                    }
                    else if (s[k - 1] == 'x')
                    {
                        animal[k] = 'W';
                    }
                    else
                    {
                        cout << "err2" << endl;
                    }
                }
                else
                {
                    cout << "err" << endl;
                    exit(1);
                }
            }

            if (check_n() && check_0())
            {
                print_anm();
            }
        }
    }
    cout << -1 << endl;
}
