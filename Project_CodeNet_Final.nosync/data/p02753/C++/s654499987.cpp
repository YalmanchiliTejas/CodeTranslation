#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string x;
    cin>>x;
    if((x[0]=='A'&&x[1]=='B')||(x[1]=='A'&&x[2]=='B')||(x[0]=='B'&&x[1]=='A')||(x[1]=='B'&&x[2]=='A'))
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
