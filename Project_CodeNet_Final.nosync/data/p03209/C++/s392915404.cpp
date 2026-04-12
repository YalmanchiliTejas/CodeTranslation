#include<iostream>
using namespace std;
typedef long long ll;

ll a[51],p[51];

ll f(int n,ll x){
	if(n==0) return x<=0?0:1;
	if(x<=1+a[n-1]) return f(n-1,x-1);
	else return p[n-1]+1+f(n-1,x-2-a[n-1]);
}

int main(){
	int n;
	ll x;
	cin >> n >> x;
	a[0]=1,p[0]=1;
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]*2+3;
		p[i]=p[i-1]*2+1;
	}
	cout << f(n,x) << endl;
	return 0;
}
