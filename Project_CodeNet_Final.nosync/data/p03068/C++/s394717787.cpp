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
  int n,k;
  string s;
  cin>>n>>s>>k;
  k--;
  char c=s[k];
  fr(i,n){
    if(s[i]==c) cout<<s[i];
    else cout<<"*";
  }
  cout<<endl;
}