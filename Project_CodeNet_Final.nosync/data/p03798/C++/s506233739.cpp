#include <bits/stdc++.h>
#define pb push_back
#define tam 100000
#define se second
#define fi first
#define pitem item*
#define forr(i,p,n) for(int i=p;i<n;i++)
using namespace std;
typedef long long ll;
const ll MOD=1000000007 ;
ll mult(ll a,ll b, ll p=MOD){return ((a%p)*(b%p))%p;}
ll add(ll a, ll b, ll p=MOD){return (a%p + b%p)%p;}
typedef pair<int,int> ii;
typedef vector<vector<int> > vvi;
typedef  double lld;
int txt[tam];
int val[tam];
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    forr(i,0,s.size())
    {
        if (s[i]=='o')
            txt[i]=0;
        else
            txt[i]=1;
    }    
    int cond,ult;
    forr(i,0,2)
    {
        val[0]=i%2;
        forr(j,0,2)
        {
            val[1]=j%2;
            ult=val[0]^txt[0]^val[1];
            //cout<<val[0]<<" "<<val[1]<<" "<<ult<<endl;
            forr(k,1,s.size()-1)
            {
                cond=val[k]^txt[k];
                val[k+1]=val[k-1]^cond;
            }
            
            if (val[n-1]==ult&& (val[n-2]^val[0])==(val[n-1]^txt[n-1]) )
            {
                forr(a,0,n)
                {
                    if (val[a]==1)
                        cout<<"W";
                    else
                        cout<<"S";
                }
                return 0;
            }
        }
    }
    cout<<-1<<endl;
}