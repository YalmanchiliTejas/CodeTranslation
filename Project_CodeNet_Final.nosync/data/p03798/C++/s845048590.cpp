#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define idfc ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
//:/
#define pb push_back
#define mp make_pair
#define nt _ll128
#define ld double
long double PI =3.14159265;
using ll = long long;

const ll modo=1e9+7;
const ll ms=2e5+5;
const ll inf=1e17;


int ar[ms];



bool go(string s,int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(ar[i])
        {
            if(s[i]=='x')
            {
                ar[i+1]=ar[i-1];
            }
            else{
                ar[i+1]=!ar[i-1];
            }
        }
        else{
            if(s[i]=='x')
            {
                ar[i+1]=!ar[i-1];
            }
            else{
                ar[i+1]=ar[i-1];
            }
        }
    }
    if(ar[0]==ar[n]&&ar[n+1]==ar[1])return true;
    return false;
}


int main()
{
    idfc;

    int  n;
    cin>>n;
    int i,j;
    string s;
    cin>>s;
    s+=s[0];


    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            ar[0]=i;
            ar[1]=j;
            if(go(s,n))
            {
                for(i=0;i<n;i++)
                {
                    if(ar[i])cout<<"W";
                    else cout<<"S";
                }
                return 0;
            }
        }
    }

    cout<<-1;


    return 0;
}