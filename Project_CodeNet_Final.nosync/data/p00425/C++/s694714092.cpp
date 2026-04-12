#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
string s;
int a[6],t,n;
void change(int b,int c,int d,int e){
  t=a[b];a[b]=a[c];a[c]=a[d];a[d]=a[e];a[e]=t;
}
int main(){
  while(cin>>n,n){
    int sum=0;
    r(i,6)a[i]=i+1;
    while(n--){
      cin>>s;
      if(s=="North")change(0,1,5,4);
      if(s=="East")change(0,3,5,2);
      if(s=="West")change(0,2,5,3);
      if(s=="South")change(0,4,5,1);
      if(s=="Right")change(1,2,4,3);
      if(s=="Left")change(1,3,4,2);
      sum+=a[0];
    }
    cout<<sum+1<<endl;
  }
}