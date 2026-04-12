#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int

int main(){
  ull n,i,j,c=0,sum=0;
  cin>>n;
  ull a[n];
  for(i=0;i<n;i++){
     cin>>a[i];
  }
  for(i=0;i<n;i++){
     for(j=0;j<=i;j++){
        if(a[i]>=a[j])
            c++;
     }
     if(c==i+1)
        sum++;

     c = 0;
  }
  cout<<sum<<endl;

  return 0;
}
