#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define eb emplace_back
#define precision(n) cout << fixed << setprecision(n);
#define fast {ios_base::sync_with_stdio(false);cin.tie(NULL);}
int main()
{
    fast;
    string s;
    cin>>s;
    int f=0;
    if(s[0]!=s[1]||s[1]!=s[2]||s[0]!=s[2])
    {
        f=1;
    }
    if(f)
    {
        cout<<"Yes"<<endl;
    }
    else
        cout<<"No"<<endl;

return 0;
}
