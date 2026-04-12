#include<bits/stdc++.h>
#include <queue>
#include <stack>
using namespace std;
 
typedef pair<long long int,long long int>pa;
#define resize(A) A.resize(unique(A.begin(), A.end()) - A.begin())
#define pb push_back
 
# define  MAX 200005
long long int MOD=998244353;
long long int INF=1e18;
 
int main()
{
    
       ios_base::sync_with_stdio(false); 
       cin.tie(NULL);
     cout.tie(NULL);
      long long int i,j,k=0,l=0,r=0,m=0,n,p=0,cnt=0,cnt1=0,x,y,z=0,a,b,low,mid,high,ans=0,maxi=0,mini=INF,t,d;
  cin>>n;
    long long int A[n];
  
    for(i=0;i<n;i++)
    {
        cin>>A[i];
        
    }
    
    multiset<long long int> lk; 
  multiset<long long int>::iterator it;
    for ( i = 0; i <n; i++)
    { 
  
       
         it=lk.lower_bound(A[i]); 
  
       
        if (it == lk.begin())
            lk.insert(A[i]); 
  
        else 
        { 
            it--; 
            lk.erase(it); 
            lk.insert(A[i]);
        } 
    } 
    cout<<lk.size();
   
}