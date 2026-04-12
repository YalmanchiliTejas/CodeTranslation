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
    if(x.find("AB")!=x.npos||x.find("BA")!=x.npos)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}