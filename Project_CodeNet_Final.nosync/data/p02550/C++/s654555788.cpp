/*  CREATED BY
    STREAM_CIPHER
    19-sep-2020
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
#define debug1(a) cout<<#a<<"="<<(a)<<"\n"
#define debug2(a,b) cout<<#a<<"="<<(a)<<","<<#b<<"="<<(b)<<"\n"
#define debug3(a,b,c) cout<<#a<<"="<<(a)<<","<<#b<<"="<<(b)<<","<<#c<<"="<<(c)<<"\n"
#define fix_precision(n) cout<<fixed<<setprecision(n)
#define all(a) a.begin(),a.end()
const double pi=acos(-1.0);
int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
const int mx=5*1000000;//5*64M bit ->5*8M byte ->40MB size for long long int (64 bit)
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
        int n,a,m;
        cin>>n>>a>>m;
        int aa;
        aa=a%m;
        int ans=0;
        ans+=aa;
        int done=1;
        int bb;
        unordered_map<int,int>taken;
        unordered_map<int,int>taken1;
        unordered_map<int,int>index;
        taken[aa]=ans;
        taken1[aa]=1;
        int gap=0;
        index[aa]=1;
        int index2;
        for(int i=2;i<=n;i++)
        {
        	bb=(aa*aa)%m;
        	// debug2(aa,bb);
        	ans+=bb;
        	done=i;
        	if(taken1[bb]!=0)
        	{
        		gap=ans-taken[bb];
        		index2=i;
        		break;
        	}
        	taken1[bb]=1;
        	index[bb]=i;
        	taken[bb]=ans;
        	aa=bb;
        }
        // debug1(gap);
        int rem=n-done;
        // debug1(rem);
        int len=abs(index[bb]-index2);
        ans+=((rem/len)*gap);
        // debug1(((rem/abs(index[bb]-index2))*gap));
        rem=rem%len;
        // debug1(rem);
        int prev=bb;
        for(int i=1;i<=rem;i++)
        {
        	ans+=(prev*prev)%m;
        	prev=(prev*prev)%m;
        }
        cout<<ans<<endl;
}
