#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
  ll n,sum=0,ans;
  cin >> n;
  ll a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  if(n%2==0){
    sort(a,a+n);
    for(int i=0;i<n/2-1;i++){
      sum += a[n-1-i]*2;
    }
    sum += a[n-1-(n/2-1)];
    for(int i=0;i<n/2-1;i++){
      sum -=a[i]*2;
    }
    sum -=a[n/2-1];
    ans = sum;
  }else{
    sort(a,a+n);
    for(int i=0;i<n/2-1;i++){
      sum += a[n-1-i]*2;
    }
    sum += a[n-1-(n/2-1)];
    sum += a[n-2-(n/2-1)];
    for(int i=0;i<n/2;i++){
      sum -= 2*a[i];
    }
    ans = sum;
    sum=0;

    for(int i=0;i<n/2;i++){
      sum += a[n-1-i]*2;
    }
    for(int i=0;i<n/2-1;i++){
      sum -= 2*a[i];
    }
    sum -= a[n/2]+a[n/2-1];
    ans = max(ans,sum);
  }
  cout <<ans<<endl;
}
