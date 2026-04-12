#include <bits/stdc++.h>

#define ll long long
#define ld long double
using namespace std;



int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    string answ;
    bool a =true;
    for (ll i = 0; i < n; i++)
        answ.push_back('W');
    if (s[0] == 'x')
    {
        for (ll i = 1; i < n-1; i++)
        {
            if (s[i] == 'x' && answ[i] == 'W')
            {
                answ[i+1] = answ[i-1];
            }
            else if (s[i] == 'o' && answ[i] == 'W')
            {
                answ[i+1] = (answ[i-1] == 'S' ? 'W' : 'S');
            }
            else if (s[i] == 'o' && answ[i] == 'S')
            {
                answ[i+1] = answ[i-1];
            }
            else if (s[i] == 'x' && answ[i] == 'S')
            {
                answ[i+1] = (answ[i-1] == 'S' ? 'W' : 'S');
            }
        }
        if (((s[n-1] == 'o' && answ[n-1] == 'S') && (answ[0] != answ[n-2])) || ((s[n-1] == 'x' && answ[n-1] == 'S') && (answ[0] == answ[n-2])))
        {
            a = false;
//            cout << -1 << endl;
//            return 0;
        }
        else if (((s[n-1] == 'x' && answ[n-1] == 'W') && (answ[0] != answ[n-2])) || ((s[n-1] == 'o' && answ[n-1] == 'W') && (answ[0] == answ[n-2])))
        {
//            cout << -1 << endl;
            a = false;
//            return 0;
        }
        else if (answ[n-1] != answ[1]) {
//            cout << -1 << endl;
            a = false;
//            return 0;
        }
        else {
            cout << answ << endl;
            return 0;
        }
        for (int i = 0; i < n; i++)
            answ[i] = 'W';
        answ[1] = 'S';
        answ[n-1] = 'S';
        for (ll i = 1; i < n-1; i++)
        {
            if (s[i] == 'x' && answ[i] == 'W')
            {
                answ[i+1] = answ[i-1];
            }
            else if (s[i] == 'o' && answ[i] == 'W')
            {
                answ[i+1] = (answ[i-1] == 'S' ? 'W' : 'S');
            }
            else if (s[i] == 'o' && answ[i] == 'S')
            {
                answ[i+1] = answ[i-1];
            }
            else if (s[i] == 'x' && answ[i] == 'S')
            {
                answ[i+1] = (answ[i-1] == 'S' ? 'W' : 'S');
            }
        }
        if (((s[n-1] == 'o' && answ[n-1] == 'S') && (answ[0] != answ[n-2])) || ((s[n-1] == 'x' && answ[n-1] == 'S') && (answ[0] == answ[n-2])))
        {
            a = false;
//            cout << -1 << endl;
//            return 0;
        }
        else if (((s[n-1] == 'x' && answ[n-1] == 'W') && (answ[0] != answ[n-2])) || ((s[n-1] == 'o' && answ[n-1] == 'W') && (answ[0] == answ[n-2])))
        {
//            cout << -1 << endl;
            a = false;
//            return 0;
        }
        else if (answ[n-1] != answ[1]) {
//            cout << -1 << endl;
            a = false;
//            return 0;
        }
        else {
            cout << answ << endl;
            return 0;
        }
    }
    else
    {
        answ[n-1] = 'S';
        for (ll i = 1; i < n-1; i++)
        {
            if (s[i] == 'o' && answ[i] == 'S')
            {
                answ[i+1] = answ[i-1];
            }
            else if (s[i] == 'x' && answ[i] == 'S')
            {
                answ[i+1] = (answ[i-1] == 'S' ? 'W' : 'S');
            }
            else if (s[i] == 'o' && answ[i] == 'W')
            {
                answ[i+1] = (answ[i-1] == 'S' ? 'W' : 'S');
            }
            else if (s[i] == 'x' && answ[i] == 'W')
            {
                answ[i+1] = answ[i-1];
            }
        }
        if (((s[n-1] == 'o' && answ[n-1] == 'S') && (answ[0] != answ[n-2])) || ((s[n-1] == 'x' && answ[n-1] == 'S') && (answ[0] == answ[n-2])))
        {
//            cout << -1 << endl;
//            return 0;
            a = false;
        }
        else if (((s[n-1] == 'x' && answ[n-1] == 'W') && (answ[0] != answ[n-2])) || ((s[n-1] == 'o' && answ[n-1] == 'W') && (answ[0] == answ[n-2])))
        {
//            cout << -1 << endl;
//            return 0;
            a = false;
        }
        else if (answ[n-1] == answ[1]) {
//            cout << -1 << endl;
//            return 0;
            a = false;
        }
        else {
            cout << answ << endl;
            return 0;
        }
        for (int i = 1; i < n; i++)
            answ[i] = 'W';
        answ[1] = 'S';
        for (ll i = 1; i < n-1; i++)
        {
            if (s[i] == 'o' && answ[i] == 'S')
            {
                answ[i+1] = answ[i-1];
            }
            else if (s[i] == 'x' && answ[i] == 'S')
            {
                answ[i+1] = (answ[i-1] == 'S' ? 'W' : 'S');
            }
            else if (s[i] == 'o' && answ[i] == 'W')
            {
                answ[i+1] = (answ[i-1] == 'S' ? 'W' : 'S');
            }
            else if (s[i] == 'x' && answ[i] == 'W')
            {
                answ[i+1] = answ[i-1];
            }
        }
        if (((s[n-1] == 'o' && answ[n-1] == 'S') && (answ[0] != answ[n-2])) || ((s[n-1] == 'x' && answ[n-1] == 'S') && (answ[0] == answ[n-2])))
        {
//            cout << -1 << endl;
//            return 0;
            a = false;
        }
        else if (((s[n-1] == 'x' && answ[n-1] == 'W') && (answ[0] != answ[n-2])) || ((s[n-1] == 'o' && answ[n-1] == 'W') && (answ[0] == answ[n-2])))
        {
//            cout << -1 << endl;
//            return 0;
            a = false;
        }
        else if (answ[n-1] == answ[1]) {
//            cout << -1 << endl;
//            return 0;
            a = false;
        }
        else {
            cout << answ << endl;
            return 0;
        }
    }


    for (ll i = 0; i < n; i++)
        answ[i] = 'S';
    if (s[0] == 'o') {
        for (ll i = 1; i < n-1; i++)
        {
            if (s[i] == 'o' && answ[i] == 'S')
            {
                answ[i+1] = answ[i-1];
            }
            else if (s[i] == 'x' && answ[i] == 'S')
            {
                answ[i+1] = (answ[i-1] == 'S' ? 'W' : 'S');
            }
            else if (s[i] == 'o' && answ[i] == 'W')
            {
                answ[i+1] = (answ[i-1] == 'S' ? 'W' : 'S');
            }
            else if (s[i] == 'x' && answ[i] == 'W')
            {
                answ[i+1] = answ[i-1];
            }
        }
        if (((s[n-1] == 'o' && answ[n-1] == 'S') && (answ[0] != answ[n-2])) || ((s[n-1] == 'x' && answ[n-1] == 'S') && (answ[0] == answ[n-2])))
        {
//            cout << -1 << endl;
//            return 0;
            a = false;
        }
        else if (((s[n-1] == 'x' && answ[n-1] == 'W') && (answ[0] != answ[n-2])) || ((s[n-1] == 'o' && answ[n-1] == 'W') && (answ[0] == answ[n-2])))
        {
//            cout << -1 << endl;
//            return 0;
            a = false;
        }
        else if (answ[n-1] != answ[1]) {
//            cout << -1 << endl;
//            return 0;
            a = false;
        }
        else {
            cout << answ << endl;
            return 0;
        }
        for (int i = 0; i < n; i++)
            answ[i] = 'S';
        answ[n-1] = 'W';
        answ[1] = 'W';
        for (ll i = 1; i < n-1; i++)
        {
            if (s[i] == 'o' && answ[i] == 'S')
            {
                answ[i+1] = answ[i-1];
            }
            else if (s[i] == 'x' && answ[i] == 'S')
            {
                answ[i+1] = (answ[i-1] == 'S' ? 'W' : 'S');
            }
            else if (s[i] == 'o' && answ[i] == 'W')
            {
                answ[i+1] = (answ[i-1] == 'S' ? 'W' : 'S');
            }
            else if (s[i] == 'x' && answ[i] == 'W')
            {
                answ[i+1] = answ[i-1];
            }
        }
        if (((s[n-1] == 'o' && answ[n-1] == 'S') && (answ[0] != answ[n-2])) || ((s[n-1] == 'x' && answ[n-1] == 'S') && (answ[0] == answ[n-2])))
        {
            a = false;
        }
        else if (((s[n-1] == 'x' && answ[n-1] == 'W') && (answ[0] != answ[n-2])) || ((s[n-1] == 'o' && answ[n-1] == 'W') && (answ[0] == answ[n-2])))
        {
            a = false;
        }
        else if (answ[n-1] != answ[1]) {
            a = false;
        }
        else {
            cout << answ << endl;
            return 0;
        }
    }
    else {
        answ[n-1] = 'W';
        for (ll i = 1; i < n-1; i++)
        {
            if (s[i] == 'o' && answ[i] == 'S')
            {
                answ[i+1] = answ[i-1];
            }
            else if (s[i] == 'x' && answ[i] == 'S')
            {
                answ[i+1] = (answ[i-1] == 'S' ? 'W' : 'S');
            }
            else if (s[i] == 'o' && answ[i] == 'W')
            {
                answ[i+1] = (answ[i-1] == 'S' ? 'W' : 'S');
            }
            else if (s[i] == 'x' && answ[i] == 'W')
            {
                answ[i+1] = answ[i-1];
            }
        }
        if (((s[n-1] == 'o' && answ[n-1] == 'S') && (answ[0] != answ[n-2])) || ((s[n-1] == 'x' && answ[n-1] == 'S') && (answ[0] == answ[n-2])))
        {
            a = false;
        }
        if (((s[n-1] == 'x' && answ[n-1] == 'W') && (answ[0] != answ[n-2])) || ((s[n-1] == 'o' && answ[n-1] == 'W') && (answ[0] == answ[n-2])))
        {
            a = false;

        }
        if (answ[n-1] == answ[1]) {
            a = false;

        }
        else {
            cout << answ << endl;
            return 0;
        }
        for (int i = 0; i < n; i++)
            answ[i] = 'S';
        answ[1] = 'W';
        for (ll i = 1; i < n-1; i++)
        {
            if (s[i] == 'o' && answ[i] == 'S')
            {
                answ[i+1] = answ[i-1];
            }
            else if (s[i] == 'x' && answ[i] == 'S')
            {
                answ[i+1] = (answ[i-1] == 'S' ? 'W' : 'S');
            }
            else if (s[i] == 'o' && answ[i] == 'W')
            {
                answ[i+1] = (answ[i-1] == 'S' ? 'W' : 'S');
            }
            else if (s[i] == 'x' && answ[i] == 'W')
            {
                answ[i+1] = answ[i-1];
            }
        }
        if (((s[n-1] == 'o' && answ[n-1] == 'S') && (answ[0] != answ[n-2])) || ((s[n-1] == 'x' && answ[n-1] == 'S') && (answ[0] == answ[n-2])))
        {
            a = false;
        }
        if (((s[n-1] == 'x' && answ[n-1] == 'W') && (answ[0] != answ[n-2])) || ((s[n-1] == 'o' && answ[n-1] == 'W') && (answ[0] == answ[n-2])))
        {
            a = false;
        }
        if (answ[n-1] == answ[1]) {
            a = false;
        }
        else {
            cout << answ << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}