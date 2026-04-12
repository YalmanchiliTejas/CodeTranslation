#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) x.begin(),x.end()
#define pb push_back
#define ff first 
#define ss second 
#define pii pair<int,int>
#define vi vector<int>
#define vc vector<char>
#define vii vector<pii>
#define vvi vector<vi>
#define fori(i,n) for(int i=1;i<=n;++i)
#define forn(i,n) for(int i=0;i<n;++i)
#define sz(x) int(x.size())
#define error(x) cout<<#x<<" "<<x<<endl
#define IOS  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const int N=100*1000;
const int mod=1e9+7;

int min3(int a,int b,int c){return min(a,min(b,c));}
int max3(int a,int b,int c){return max(a,max(b,c));}
int min4(int a,int b,int c,int d){return min(min(a,b),min(c,d));}
int max4(int a,int b,int c,int d){return max(max(a,b),max(c,d));}

//#define int int64_t
int a[N+2];

int32_t  main(){
	IOS;
  int n;cin>>n;  
  fori(i,n){cin>>a[i];}
  int ans=0;
  fori(i,n){
    bool flag=true;
    for(int j=1;j<i;++j){
      if(a[j]>a[i]){flag=false;break;}
    }
    if(flag)ans++;
  }
  cout<<ans<<endl;
  return 0;
}

