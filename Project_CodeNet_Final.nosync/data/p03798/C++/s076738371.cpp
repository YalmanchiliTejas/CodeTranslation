#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pi acos(-1.0)
#define eps 1e-9
#define ll long long
#define ull unsigned long long
#define sf scanf
#define pf printf
#define nl printf("\n")
#define ps(s) printf("%s",s.c_str())
#define inf (ll)1e15
#define mod 1000000007
#define mem(x,val) memset(x,val,sizeof x)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend() 
#define sz(x) (int)(x).size()
#define test_case int ___t;scanf("%d", &___t);for(int cs=1;cs<=___t;cs++)

using namespace __gnu_pbds;
using namespace std;

inline string str_inp(int n){char ch[n+5];sf(" %s",ch);return string(ch);}
inline string line_inp(int n)
{char ch[n+5];fgets(ch,n+5,stdin);string s=string(ch);s.pop_back();return s;}

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;

const int S=100100;

int n;
string s;
string ans;

bool Check()
{
    for(int i=1;i<n-1;i++)
    {
        if(s[i]=='o')
        {
            if(ans[i]=='S')
            {
                if(ans[i-1]=='S')ans[i+1]='S';
                else ans[i+1]='W';
            }
            else 
            {
                if(ans[i-1]=='W')ans[i+1]='S';
                else ans[i+1]='W';
            }
        }
        else
        {
            if(ans[i]=='S')
            {
                if(ans[i-1]=='W')ans[i+1]='S';
                else ans[i+1]='W';
            }
            else
            {
                if(ans[i-1]=='S')ans[i+1]='S';
                else ans[i+1]='W';
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        int id;
        if(i==0)id=n-1;
        else id=i-1;

        if(s[i]=='o' && ans[i]=='S' && ans[id]!=ans[(i+1)%n])return false;
        if(s[i]=='x' && ans[i]=='W' && ans[id]!=ans[(i+1)%n])return false;
        if(s[i]=='o' && ans[i]=='W' && ans[id]==ans[(i+1)%n])return false;
        if(s[i]=='x' && ans[i]=='S' && ans[id]==ans[(i+1)%n])return false;
    }
    return true;
}

int main()
{
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //#endif
    while(~sf("%d",&n))
    {
        s=str_inp(n+5);

        string t="SW";
        bool f=true;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                ans.resize(n);
                ans[0]=t[i];
                ans[1]=t[j];
                if(Check())
                {
                    ps(ans),nl;
                    f=false;
                    break;
                }
            }
            if(!f)break;
        }
        if(f)puts("-1");
    }
    return 0;
}
 




































