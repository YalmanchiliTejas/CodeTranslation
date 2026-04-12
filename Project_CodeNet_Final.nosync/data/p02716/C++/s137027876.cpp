#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define double long double
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mod 1000000007
#define ceil(a,b) (a+b-1)/b
#define endl "\n"

#define oa(A) for(auto i:A)   cout<<i<<" ";cout<<endl;
#define o1(a) cout<<" "<<#a<<" : "<<a<<"\n"
#define o2(a,b) cout<<" "<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<"\n"
#define o3(a,b,c) cout<<" "<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<"\n"
#define o4(a,b,c,d) cout<<" "<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<"\n"

 const int N=100005;
 const int inf=1e18;
 const double eps=1e-9;
int pow1(int a,int b){
    int res=1;
    while(b>0){
        if(b&1){
        	res=res*a;
		}
        a=a*a;
        b>>=1;
    }
    return res;
}
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int n;
    cin>>n;
    int a[n];
    for(int x=0;x<n;x++){
        cin>>a[x];
    }
    // int s1=0,s2=0;
    if(n==1){
        cout<<a[0];
        return 0;
    }
    if(n==2){
        cout<<max(a[0],a[1]);
        return 0;
    }
    if(n%2==0){
        int s[n][2];
        for(int x=0;x<n;x++){
            s[x][0]=-1*inf,s[x][1]=-1*inf;
        }
        s[0][1]=a[0];
        s[0][0]=-1*inf;
        s[1][1]=a[1];
        s[1][0]=-1*inf;
        s[2][1]=s[0][1]+a[2];
        s[2][0]=a[2];
        for(int x=3;x<n;x++){
            s[x][1]=s[x-2][1]+a[x];
            s[x][0]=max(s[x-2][0]+a[x],s[x-3][1]+a[x]);
        }
        int ans=max(s[n-1][0],s[n-2][1]);
        // ans=max(ans,s[n-1][0]);
        ans=max(ans,s[n-1][1]);
        cout<<ans;
        return 0;



    }else{
        int s[n][3];
        for(int x=0;x<n;x++){
            s[x][0]=-1*inf,s[x][1]=-1*inf,s[x][2]=-1*inf;
        }
        s[0][2]=a[0];
        s[0][0]=-1*inf;
        s[0][1]=s[0][0];
        s[1][2]=a[1];
        s[1][0]=-1*inf;
        s[1][1]=s[1][0];
        s[2][2]=s[0][2]+a[2];
        s[2][1]=a[2];
        s[2][0]=-1*inf;
        for(int x=3;x<n;x++){
            s[x][2]=s[x-2][2]+a[x];
            s[x][0]=max(s[x-2][0]+a[x],s[x-3][1]+a[x]);
            if(x!=3){
                s[x][0]=max(s[x][0],s[x-4][2]+a[x]);
            }
            s[x][1]=max(s[x-2][1]+a[x],s[x-3][2]+a[x]);
            // if(x!=3){
            //     s[x][1]=max(s[x][1],s[x-4][2]+a[x]);
            // }
        }
        int ans=max(s[n-2][1],s[n-2][2]);
        // ans=max(ans,s[n-2][2]);  
        ans=max(ans,s[n-1][0]);
        ans=max(ans,s[n-1][1]);
        ans=max(ans,s[n-3][2]);
        cout<<ans;
    }








	
return 0;
}
