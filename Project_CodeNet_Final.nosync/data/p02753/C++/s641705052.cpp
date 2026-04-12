#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int num[2];

int main()
{
    string S;
    cin >> S;
    for(auto &p : S) ++num[p-'A'];
    if(num[0] == 0 || num[1] == 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}