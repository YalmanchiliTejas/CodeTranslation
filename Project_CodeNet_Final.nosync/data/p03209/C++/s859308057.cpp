#include <bits/stdc++.h>

using namespace std;
  
#define rep(i,n) for(int i=1;i<n;i++)  
  
long n,x;  
long a[50],p[50];  
  
long f(long n, long x){
 if(n==0){
   if(x>=1) return 1;
   else return 0;
 }
 else if(x<=1+a[n-1]) {
   return f(n-1,x-1);
 }
 else {
   return p[n-1]+1+f(n-1,x-2-a[n-1]);
 }

}  
  
  
int main(){
  cin >> n >> x;
  
  a[0]=1;
  p[0]=1;
  rep(i,n) {
    a[i]=2*a[i-1]+3;
    p[i]=2*p[i-1]+1;
  }
     
  cout << f(n,x) << endl;
}