#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
  int n;
  cin>>n;
  long a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  sort(a, a+n);
  long long ans=0;
  long left=a[0];
  long right=a[0];
  int first=1;
  int last=n-1;
  while(first<=last){
    long v1=abs(left-a[first]);
    long v2=abs(left-a[last]);
    long v3=abs(right-a[first]);
    long v4=abs(right-a[last]);
    if(v1>=v2&&v1>=v3&&v1>=v4){
      ans+=v1;
      left=a[first];
      ++first;
    }else if(v2>=v3&&v2>=v4){
      ans+=v2;
      left=a[last];
      --last;
    }else if(v3>=v4){
      ans+=v3;
      right=a[first];
      ++first;
    }else{
      ans+=v4;
      right=a[last];
      --last;
    }
  }
  cout<<ans<<endl;

}