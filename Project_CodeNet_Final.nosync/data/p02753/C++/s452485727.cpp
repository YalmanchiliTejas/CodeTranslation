#include <iostream>
#include <string>
#include <algorithm>
#define rep(i,n) for(int i=0;, i < n; i++)
#define rep_2(i,n) for(int i=n, i > 0; i--)
using namespace std;
using ln = long long;

int main()
{
    string s;
    cin >> s;

    if(s=="AAA" || s=="BBB")
        cout << "No" << endl;
    else
        cout << "Yes" << endl;

    return 0;
}