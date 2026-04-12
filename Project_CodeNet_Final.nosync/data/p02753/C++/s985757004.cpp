#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

string S;
void input()
{
    cin>>S;
}

void solve()
{
    string ans="Yes";
    if(S=="AAA" || S=="BBB") ans="No";
    cout<<ans<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}