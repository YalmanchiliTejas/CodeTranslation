#include<bits/stdc++.h>
#include<ext/rope>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define C 0.5772156649
#define pi acos(-1.0)
#define ll long long
#define mod 1000000007
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1

using namespace std;
using namespace __gnu_cxx;

const double g=10.0,eps=1e-7;
const int N=100+10,maxn=100000+10,inf=0x3f3f3f;

int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s.substr(i,2)=="AC")
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}
/*******************

********************/
