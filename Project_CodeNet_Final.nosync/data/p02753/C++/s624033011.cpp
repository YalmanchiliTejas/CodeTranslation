#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define FOR(i,l,r) for(long long i=l; i<r; i++)
#define FOR_REV(i,r,l) for(long long i=r; i>=l; i--)
#define pb push_back
#define mp make_pair

int main()
{
    string s;
    cin>>s;

    int cnt=0;
    for (int i=0; i<3; i++)
    {
        if (s[i] == 'A')
        {
            cnt++;
        }
    }
    if (cnt == 0 || cnt == 3)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
    }
}
