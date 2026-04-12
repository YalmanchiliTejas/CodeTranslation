/*coderanant*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define f1(i,a,b) for(i=a;i<b;i++)
#define f2(i,a,b) for(i=a;i>=b;i--)
#define endl '\n'
#define pb push_back
#define gp " "
#define ff first
#define ss second
#define mp make_pair

const int mod=1000000007;
int i,j;
ll temp;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    f1(i,0,n)
    cin>>a[i];
    int lar=a[0];
    int ans=1;
    f1(i,1,n)
    {
    	if(a[i]>=lar)
    	{
    		ans++;
    		lar=a[i];
    	}
    }
    cout<<ans;
    return 0;
}