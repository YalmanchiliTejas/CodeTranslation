#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sc(n) scanf("%d",&n)
#define scl(n) scanf("%lld",&n)
#define pr(n) printf("%d",n)
#define prl(n) printf("%lld",n)
#define nl printf("\n")
#define fr(i,n) for(i=0;i<n;i++)

typedef long long ll;
pair<int,int> A[200010];
int ans[200010];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1,n,i,j;
    cin>>n;
    fr(i,n){cin>>A[i].f;A[i].s=i;}
    sort(A,A+n);
    int num = n/2;
    fr(i,n)
    {
        int prv = i;
        if (prv >= num)ans[A[i].s]=A[num-1].f;
        else 
        {
        ans[A[i].s]=A[num].f;
        }

    }
    fr(i,n)cout<<ans[i]<<"\n";

    
    return 0;
}
