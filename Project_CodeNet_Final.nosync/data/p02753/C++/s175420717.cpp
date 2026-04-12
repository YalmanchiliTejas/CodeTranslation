#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const ll maxn = 1e6 + 5;
ll a,b,c,t,n,m;
ll num[maxn];
string str;
int main()
{
    cin >> str;
    if(str[0] == str[1] && str[2] == str[1])
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}
