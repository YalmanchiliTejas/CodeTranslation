#include<cstdio>
#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include <set>
#include<algorithm>
#include<string.h>
#include<math.h>

using namespace std;

int main(int argc, char* argv[]){
  int n;
  scanf("%d",&n);
  long long int a[100001];
  long long int b[100001];
  for(int i=0;i<n;i++){
    scanf("%lld",&a[i]);
  }
  long long int ans=0;

  sort(a,a+n);
  if(n%2==1){
    long long int ans1=0;
    long long int ans2=0;
    //mid>>max
    b[0]=a[n/2];
    for(int i=1;i<n;i++){
      if(i%2==1){b[i]=a[(n-1)-(i/2)];}
      else{b[i]=a[(i-1)/2];}
    }
    for(int i=1;i<n;i++){
      ans1+=abs(b[i]-b[i-1]);
    }
    for(int i=1;i<n;i++){
      if(i%2==0){b[i]=a[n-(i/2)];}
      else{b[i]=a[(i-1)/2];}
    }
    for(int i=1;i<n;i++){
      ans2+=abs(b[i]-b[i-1]);
    }
    //mid>>min
    ans = max({ans1,ans2});
    cout << ans << endl;
    return 0;
  }
  else{
    long long int ans1=0;
    long long int ans2=0;
    long long int ans3=0;
    long long int ans4=0;
    b[0]=a[n/2];
    //mid+>>max
    for(int i=1;i<n;i++){
      if(i%2==1){b[i]=a[(n-1)-(i/2)];}
      else{b[i]=a[(i-1)/2];}
    }
    for(int i=1;i<n;i++){
      ans1+=abs(b[i]-b[i-1]);
    }
    //mid+>>min
    for(int i=1;i<n;i++){
      if(i%2==0){b[i]=a[n-(i/2)];}
      else{b[i]=a[(i-1)/2];}
    }
    for(int i=1;i<n;i++){
      ans2+=abs(b[i]-b[i-1]);
    }
    b[0]=a[(n-1)/2];
    //mid->>max
    for(int i=1;i<n;i++){
      if(i%2==1){b[i]=a[(n-1)-(i/2)];}
      else{b[i]=a[(i-1)/2];}
    }
    for(int i=1;i<n;i++){
      ans3+=abs(b[i]-b[i-1]);
    }
    //mid->>min
    for(int i=1;i<n;i++){
      if(i%2==0){b[i]=a[n-(i/2)];}
      else{b[i]=a[(i-1)/2];}
    }
    for(int i=1;i<n;i++){
      ans4+=abs(b[i]-b[i-1]);
    }
    ans = max({ans1,ans2,ans3,ans4});
    cout << ans << endl;
    return 0;
  }
  return 0;
}
