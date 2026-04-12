//Robs Code
/***********HEADER***************/
#include<bits/stdc++.h>
/***********MACROS***************/
#define int long long int
#define fri(l,k) for (i=l;i<=k;i++)
#define frj(l,k) for (j=l;j>=k;j--)
#define fij(a,b,l,k) for(i=a;i<=b;i++) for(j=l;j<=k;j++)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define endl "\n"
#define pb push_back
#define _1 first
#define _2 second
#define mxsz 10000007
#define mxval 1e9
#define grt [](auto x,auto y){return x>y;}
#define pii pair<int,int>
/*********VARIABLE****************/
using namespace std;
int i,j,n,m,k,l,q,t,a,b,sum[3],tot[3],cnt[3];
/***********MAIN******************/
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
    string s;
    cin>>s;
    cin>>k;
    for(i=0;i<n;i++){
        if(s[k-1]!=s[i]){
            cout<<"*";
        }else cout<<s[i];
    }
	return 0;
}
//.........
