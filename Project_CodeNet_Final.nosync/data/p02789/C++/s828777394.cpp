#include <iostream>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<stack>
#include<map>
#include<deque>
#include<cstdio>
#include<cstdio>
#include<time.h>
using namespace std;
#define rep(i,a) for(int i=0;i<a;i++)
#define pd(a,n) for(int i=0;i<n;i++)cout<<a[i]<<((i==n-1)?"\n":" ")
#define pdd(a,n,m)for(int i=0;i<m;i++)pd(a,m)
#define mp make_pair
#define pb push_back
#define ll __int64
#define __int64 long long
#define P pair<int,int>
#define PP pair<P,int>

int n,m;

int main(){
  cin>>n>>m;
  if(n==m)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  return 0;
}
