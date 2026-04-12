#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
#define ll long long
using namespace std;

int main() {
  int a,b,c,X,Y; cin>>a>>b>>c>>X>>Y;
  int res=1e9;
  for (int AB=0; AB<=200000; AB+=2) {
    int tmp=0;
    tmp+=AB*c;
    int aa=X-AB/2;
    int bb=Y-AB/2;
    if (aa>0) tmp+=aa*a;
    if (bb>0) tmp+=bb*b;
    res=min(res, tmp);
  }
  cout<<res<<endl;
}
