#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> II;
typedef vector< II > VII;
typedef vector<int> VI;

#define endl "\n"
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ll long long
#define fr(i,n) for(i=0;i<n;i++)


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,k,cnt=0,i;
    cin>>n>>k;
    if(k==0)
        cout<<n*n<<endl;
    else
    {
        for(i=k+1;i<=n;i++)
        {
            cnt+=((n/i)*(i-k));
            cnt+=max((ll)0,(n%i)-k+1);
        }
        cout<<cnt<<endl;
    }
    return 0;
}
