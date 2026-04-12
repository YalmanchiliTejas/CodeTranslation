#include <bits/stdc++.h>
using namespace std;
long p(long n,long x){
    if(n==0&&x==1) return 1;
    if(x==1) return 0;
    if(2<=x&&x<=pow(2,n+1)-2) return p(n-1,x-1);
    if(x==pow(2,n+1)-1) return pow(2,n);
    if(pow(2,n+1)<=x&&x<=pow(2,n+2)-4) return pow(2,n)+p(n-1,x-pow(2,n+1)+1);
    if(x==pow(2,n+2)-3) return pow(2,n+1)-1;
}
int main(){
  long n,x;
  cin >> n >> x;
  cout << p(n,x) << endl;
}