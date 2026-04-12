#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,n) for(i=a;i<n;i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef pair<int,int> pii;

int main(void) {
  int i,j;
  int n;
  while(1){
    cin>>n;
    if(n==0)break;
    vi a(7);
    rep(i,7)a[i]=i;
    int ans=0;
    rep(i,n){
      string s;
      cin>>s;
      if(s=="South"){
	a[0]=a[2];
	a[2]=a[1];
	a[1]=a[5];
	a[5]=a[6];
	a[6]=a[0];
      }else if(s=="West"){
	a[0]=a[4];
	a[4]=a[1];
	a[1]=a[3];
	a[3]=a[6];
	a[6]=a[0];
      }else if(s=="East"){
	a[0]=a[3];
	a[3]=a[1];
	a[1]=a[4];
	a[4]=a[6];
	a[6]=a[0];
      }else if(s=="North"){
	a[0]=a[5];
	a[5]=a[1];
	a[1]=a[2];
	a[2]=a[6];
	a[6]=a[0];
      }else if(s=="Left"){
	a[0]=a[3];
	a[3]=a[2];
	a[2]=a[4];
	a[4]=a[5];
	a[5]=a[0];
      }else if("Right"){
	a[0]=a[4];
	a[4]=a[2];
	a[2]=a[3];
	a[3]=a[5];
	a[5]=a[0];
      }
      ans+=a[1];
    } 
    cout<<1+ans<<endl;
  }
}