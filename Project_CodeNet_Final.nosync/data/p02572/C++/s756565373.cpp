#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;
long long add_mod(long long a,long long b){
	long long re = (a%mod)+(b%mod);
	return re%mod;
}
long long mul_mod(long long a,long long b){
	long long re = (a%mod)*(b%mod);
	return re%mod;
}

//return = a - b;
long long sub_mod(long long a,long long b){
	long long re;
	if(a%mod < b%mod){
		re = (a%mod)+mod - (b%mod);
	}
	else{
		re = (a%mod) - (b%mod);
	}
	return re;
}

int main(void){
    int n;
    cin>>n;
    long long a[n+1];
    long long b[n+1];
    for(int i = 1; i < n+1; i++) b[i] = 0;
    b[0] = 0;
    long long all = 0;
    for(int i = 1; i < n+1; i++){
        cin>>a[i];
        b[i] = add_mod(a[i], b[i-1]);
        all = add_mod(a[i],all);
    }
    long long ans,w;
    ans = 0;
    w = 0;
    long long sa;
    for(int i = 1; i < n; i++){
        sa = sub_mod(all,b[i]);
        w = mul_mod(sa,a[i]);
        ans = add_mod(w,ans);
    }

    cout<<ans<<endl;
    return 0;
}