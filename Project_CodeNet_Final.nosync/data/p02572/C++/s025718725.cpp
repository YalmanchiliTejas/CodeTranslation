/******************************************
* AUTHOR : GURUTEJA *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define N 100005
#define MOD 1000000007
#define dd double
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second


  int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n;
    cin>>n;
     long long int a[n],cons=1000000000+7,s=0,ans=0;
    for(int i=0; i<n; i++){
    	cin>>a[i];
    }
    s=0;
    for(int i=n-1; i>=0; i--){
       ans+=((a[i]%cons)*s)%cons;
       s+=(a[i]%cons);
       s%=cons;
       ans%=cons;
    }
    cout<<ans<<endl;
    return 0;
  }