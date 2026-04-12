#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll MOD = 1000000007;
const ll N=1e5+9;
int main()
{
    FASTINOUT;
    string s;
    cin>>s;
    if (s.find('A')!=-1&&s.find('B')!=-1)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}
