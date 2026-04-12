#include <iostream>
#include <algorithm>
using namespace std;

long long m(long long n){
    if(n==0) return 1;
    else{
        
        long long z=2*m(n-1)+3;
        return z;
    }
}
long long f(long long n,long long x){
    if(x==0) return 0;
    else if (n==0) return 1;
    else if (x<=m(n-1)+1){
        long long a=f(n-1,x-1);
        return a;
    }
    else if(x<m(n)){
        long long b=f(n-1,m(n-1))+1+f(n-1,x-m(n-1)-2);
        return b;
    }
    else{
        long long c=2*f(n-1,m(n-1))+1;
        return c;
    }
}
int main() {
	long long n,k;
	cin>>n>>k;
	
	cout<<f(n,k);
	return 0;
}
