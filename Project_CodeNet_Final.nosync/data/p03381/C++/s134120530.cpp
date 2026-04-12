#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define fr(i,n) for(int i=0;i<n;i++)

int main(){
  ll n,a[200010],b[200010],c,d;
  cin >>n;
  fr(i,n){cin>>a[i];b[i]=a[i];}
  sort(a,a+n);
  c=a[n/2];
  d=a[(n/2)-1];
  fr(i,n){
    if(b[i]>=c) cout<<d<<endl;
    else cout<<c<<endl;
  }
}