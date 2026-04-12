//Robs Code
#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long int
#define fri(l,k) for (i=l;i<=k;i++)
#define frj(l,k) for (j=l;j>=k;j--)
#define all(x) x.begin(),x.end()
#define ed cout<<"\n";
#define pb push_back
#define pii pair<int,int>
#define _1 first
#define _2 second
#define maxi 100000007
/**********************************************************/
using namespace std;
int i,j,k,n,m,q,t,a,b,cnt,sum,tot;
signed main() 
{
    speed;
    cin>>n;
    vector<int> v(n);
    fri(0,n-1) cin>>v[i];
    int mx=INT_MIN;
    for(i=0;i<n;i++){
        if(v[i]>=mx){
            cnt++;
            mx=v[i];
        }
    }
    cout<<cnt;
    return 0;
}
