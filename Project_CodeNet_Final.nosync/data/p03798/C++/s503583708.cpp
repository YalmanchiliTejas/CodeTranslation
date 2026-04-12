#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin >> n >> s;

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            for(int k = 0; k < 2; k++)
            {
                // 1 : S, -1 : W
                vector<int> animal(n);
                if(i == 0) animal[0] = 1;
                else animal[0] = -1;
                if(j == 0) animal[1] = 1;
                else animal[1] = -1;
                if(k == 0) animal[n-1] = 1;
                else animal[n-1] = -1;

                for(int m = 1; m < n-2; m++)
                {
                    char c = s[m];
                    if(animal[m] == 1)
                    {
                        if(c == 'o') animal[m+1] = animal[m-1];
                        else animal[m+1] = -animal[m-1]; 
                    }
                    else
                    {
                        if(c == 'o') animal[m+1] = -animal[m-1];
                        else animal[m+1] = animal[m-1]; 
                    }
                }
                // n-2
                if(animal[n-2] == 1)
                {
                    char c = s[n-2];
                    if(c == 'o')
                    {
                        if(animal[n-1] != animal[n-3]) continue;
                    }
                    else
                    {
                        if(animal[n-1] == animal[n-3]) continue;
                    }
                }
                else
                {
                    char c = s[n-2];
                    if(c == 'o')
                    {
                        if(animal[n-1] == animal[n-3]) continue;
                    }
                    else
                    {
                        if(animal[n-1] != animal[n-3]) continue;
                    }
                }
                // n-1
                if(animal[n-1] == 1)
                {
                    char c = s[n-1];
                    if(c == 'o')
                    {
                        if(animal[0] != animal[n-2]) continue;
                    }
                    else
                    {
                        if(animal[0] == animal[n-2]) continue;
                    }
                }
                else
                {
                    char c = s[n-1];
                    if(c == 'o')
                    {
                        if(animal[0] == animal[n-2]) continue;
                    }
                    else
                    {
                        if(animal[0] != animal[n-2]) continue;
                    }
                }
                // 0
                if(animal[0] == 1)
                {
                    char c = s[0];
                    if(c == 'o')
                    {
                        if(animal[1] != animal[n-1]) continue;
                    }
                    else
                    {
                        if(animal[1] == animal[n-1]) continue;
                    }
                }
                else
                {
                    char c = s[0];
                    if(c == 'o')
                    {
                        if(animal[1] == animal[n-1]) continue;
                    }
                    else
                    {
                        if(animal[1] != animal[n-1]) continue;
                    }
                }
                for(int m = 0; m < n; m++)
                {
                    if(animal[m] == 1) cout << 'S';
                    else cout << 'W';
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}

