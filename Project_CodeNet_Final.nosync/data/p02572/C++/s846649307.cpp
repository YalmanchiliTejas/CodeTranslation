#include<bits/stdc++.h>
using namespace std;
const int MX=2e5+5;
const int M=1e9+7;
long long n,p,q,r,x;
long long f(long long x,long long y){
    long long k=1;
    while(y){
        if(y&1) k = ((k%M)*(x%M))%M;
        y>>=1;
        x = ((x%M)*(x%M))%M;
    }
    if(k<0) k+=M; 
    return k;
}
int main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        p+=x;
        p%=M;
        q+=x*x;
        q%=M;
    }
    r=f(2,M-2);
    p = ((p%M)*(p%M))%M;
    if(p<0) p+=M;
    p = ((p%M)-(q%M))%M;
    p = ((p%M)*(r%M))%M;;
    if(p<0) p+=M;
    cout << p;
    return 0;
}