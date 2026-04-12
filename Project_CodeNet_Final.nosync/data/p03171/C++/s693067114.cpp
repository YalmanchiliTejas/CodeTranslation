#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define fi first
#define se second
#define fr(i,l,r) for(int i=l;i<=r;i++)
int d[3000][3000];
int n;
int a[3000];
int deq(int i,int j)
{int l = n-(j-i+1)+1;
	if(j<i)return 0;
    if(d[i][j]!=-1)return d[i][j];
     
	if(l%2==0)
	      {
             d[i][j]=min(deq(i+1,j)-a[i],deq(i,j-1)-a[j]);
	      }
		else
		  {
              d[i][j]=max(deq(i+1,j)+a[i],deq(i,j-1)+a[j]);
		  }
		  return d[i][j];
}
signed main()
{   //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int n;
    cin>>n;
    memset(d,-1,sizeof(d[0][0])*3000*3000);
    for(int i=0;i<n;i++)cin>>a[i];
    
    cout<<deq(0,n-1)<<endl;


    return 0;
}