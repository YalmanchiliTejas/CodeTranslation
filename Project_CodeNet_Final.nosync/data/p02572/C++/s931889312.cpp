#include<bits/stdc++.h>
#define lld long long int
#define vec vector<lld>
#define pll pair<lld,lld>
#define pb push_back
#define ss second
#define ff first
#define mp make_pair
#define mod 1000000007
#define answer(x) cout<<endl<<"answer : "<<x<<endl<<endl;
#define op(x) cout<<x<<endl;
#define maxn 500005
#define messi ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main() {messi lld t=1;//cin>>t;
    while(t--)
    {
        lld n=0,m=0,k=0,i=0,j=0,p=0,q=0,x=0,y=0,z=0,ans=0,cnt=0,l=0,r=1,mid=0,lo=0,hi=0;string s;bool flag=false;
        cin>>n; lld a[n]; for(i=0;i<n;i++) cin>>a[i];
        lld dp[n];
        dp[n-1]=0;
        for(i=n-2;i>=0;i--)
            dp[i]=dp[i+1]+a[i+1];
        for(i=0;i<n;i++)
            cnt=(cnt%mod +(a[i]%mod * (dp[i]%mod)))%mod;
        cout<<cnt<<endl;
    }
	return 0;
}
/*  CODED BY:-
 ________________________________________
|            __        __                |
|  /\   /\  |__)  /\  |  \ |__| \ /  /\  |
| /~~\ /~~\ |  \ /~~\ |__/ |  |  |  /~~\ |
|________________________________________|

*/
