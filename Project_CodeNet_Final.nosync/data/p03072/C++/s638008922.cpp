#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
#define pb push_back
#define ft first
#define sd second
#define mp make_pair
#define fr(i,n) for(int i=0;i<(n);i++)
#define Fr(i,n) for(int i=0;i++<(n);)
#define ifr(i,n) for(int i=(n)-1;i>=0;i--)
#define iFr(i,n) for(int i=(n);i>0;i--)

int main(){
  int n,h,k,c=1;
  cin>>n;
  cin>>k;
  fr(i,n-1){
    cin>>h;
    k=max(k,h);
    if(k==h) c++;
  }
  cout<<c<<endl;
}