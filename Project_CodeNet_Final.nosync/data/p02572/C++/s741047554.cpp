#include <bits/stdc++.h>
 
using namespace std; 

#define m 1000000007

long long int binpow(long long int a, long long int b, long long int mm) {
    a %= mm;
    long long int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mm;
        a = a * a % mm;
        b >>= 1;
    }
    return res;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n;
    cin>>n;
    long long int s1=0,s2=0;
    while(n--){
    	long long int x;
    	cin>>x;
    	s1=(s1+x)%m;
    	long long int val=(x%m)*(x%m);
    	s2=(s2+val)%m;
	}
	s1=(s1*s1)%m;
	long long int sum=((s1-s2)%m +m)%m;
	long long int tp=binpow(2,1000000005,m);
	long long int ans=((sum%m)*(tp%m))%m;
	cout<<ans;
	return 0;
}