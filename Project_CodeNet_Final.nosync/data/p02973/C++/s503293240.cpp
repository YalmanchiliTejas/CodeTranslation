#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a;
  cin >> n;
  int b[n];
  b[0]=1234567890;
  cin >> b[1];
  b[2]=-1;
  int res=1;
  int j=0;
  int left=0;
  int right,mid;
  for(int i=1;i<n;i++){
    left=0;
    right=res+1;
    cin >> a;
    while(left<right){
      mid=(left+right)/2;
      if(b[mid]>=a)left=mid;
      if(b[mid]<a)right=mid;
      if(right-left==1)left=right;
    }
    if(b[right]==-1){
      b[right+1]=-1;
      res++;
    }
    b[right]=a;
  }
  cout << res << endl;
}
