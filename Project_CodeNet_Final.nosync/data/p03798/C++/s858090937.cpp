#include <iostream>
#include <string>
using namespace std;

bool checkString(int n, string s1, string s2, char spec1, char spec2)
{
    s2[0] = spec1;
    s2[1] = spec2;
    
    for(int i = 1; i < n - 1; i++)
    {
        if(s1[i] == 'o' && s2[i] == 'S')
        {
            s2[i + 1] = s2[i - 1];
        }
        else if(s1[i] == 'o' && s2[i] == 'W')
        {
            if(s2[i - 1] == 'S')
            {
                s2[i + 1] = 'W';
            }
            else
            {
                s2[i + 1] = 'S';
            }
        }
        else if(s1[i] == 'x' && s2[i] == 'S')
        {
            if(s2[i - 1] == 'S')
            {
                s2[i + 1] = 'W';
            }
            else
            {
                s2[i + 1] = 'S';
            }
        }
        else if(s1[i] == 'x' && s2[i] == 'W')
        {
            s2[i + 1] = s2[i - 1];
        }
    }
    
    bool firstCheck = false;
    
    if(s1[n - 1] == 'o' && s2[n - 1] == 'S')
    {
        if(s2[0] == s2[n - 2])
            firstCheck = true;
        else
            return false;
    }
    else if(s1[n - 1] == 'o' && s2[n - 1] == 'W')
    {
        if(s2[0] != s2[n - 2])
            firstCheck = true;
        else
            return false;
    }
    else if(s1[n - 1] == 'x' && s2[n - 1] == 'S')
    {
        if(s2[0] != s2[n -2])
            firstCheck = true;
        else
            return false;
    }
    else if(s1[n - 1] == 'x' && s2[n - 1] == 'W')
    {
        if(s2[0] == s2[n - 2])
            firstCheck = true;
        else
            return false;
    }
    else
        return false;
    
    if(firstCheck)
    {
        if(s1[0] == 'o' && s2[0] == 'S')
        {
            if(s2[n - 1] == s2[1])
                return true;
            else
                return false;
        }
        else if(s1[0] == 'o' && s2[0] == 'W')
        {
            if(s2[n - 1] != s2[1])
                return true;
            else
                return false;
        }
        else if(s1[0] == 'x' && s2[0] == 'S')
        {
            if(s2[n - 1] != s2[1])
                return true;
            else
                return false;
        }
        else if(s1[0] == 'x' && s2[0] == 'W')
        {
            if(s2[n - 1] == s2[1])
                return true;
            else
                return false;
        }
        else
            return false;
    }
    
    return false;
}

string changeString(int n, string s1, string s2, char spec1, char spec2)
{
    s2[0] = spec1;
    s2[1] = spec2;
    
    for(int i = 1; i < n - 1; i++)
    {
        if(s1[i] == 'o' && s2[i] == 'S')
        {
            s2[i + 1] = s2[i - 1];
        }
        else if(s1[i] == 'o' && s2[i] == 'W')
        {
            if(s2[i - 1] == 'S')
            {
                s2[i + 1] = 'W';
            }
            else
            {
                s2[i + 1] = 'S';
            }
        }
        else if(s1[i] == 'x' && s2[i] == 'S')
        {
            if(s2[i - 1] == 'S')
            {
                s2[i + 1] = 'W';
            }
            else
            {
                s2[i + 1] = 'S';
            }
        }
        else if(s1[i] == 'x' && s2[i] == 'W')
        {
            s2[i + 1] = s2[i - 1];
        }
    }
    
    return s2;
}

int main()
{
    int n;
    string s, s2;
    cin >> n >> s;
    s2 = s;
    
    if(checkString(n, s, s2, 'S', 'S'))
        cout << changeString(n, s, s2, 'S', 'S') << endl;
    else if(checkString(n, s, s2, 'S', 'W'))
        cout << changeString(n, s, s2, 'S', 'W') << endl;
    else if(checkString(n, s, s2, 'W', 'S'))
        cout << changeString(n, s, s2, 'W', 'S') << endl;
    else if(checkString(n, s, s2, 'W', 'W'))
        cout << changeString(n, s, s2, 'W', 'W') << endl;
    else
        cout << "-1" << endl;
    
    return 0;
}
