#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
long b(long n,long x){
    if(n==0) return 1;
    if(x==1) return 0;
    else if(2<=x&&x<=pow(2,n+1)-2) return b(n-1,x-1);
    else if(x==pow(2,n+1)-1) return pow(2,n);
    else if(pow(2,n+1)<=x&&x<=pow(2,n+2)-4) return pow(2,n)+b(n-1,x-pow(2,n+1)+1);
    else if(pow(2,n+2)-3) return pow(2,n+1)-1;
}
int main(){
    long n,x;
    cin >> n >> x;
    cout << b(n,x) << endl;
}