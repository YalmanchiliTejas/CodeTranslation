#include <bits/stdc++.h>
using namespace std;
#define sws                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define s string
#define ll long long;

int main()
{
    sws;
    int age;
    cin >> age;
    if (age == 3 or age == 5 or age == 7)
        cout << "YES" << endl;
    else
    {
        cout << "NO" << endl;
    }
}