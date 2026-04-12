#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i, s, n) for (int i = (s); i <= (int)(n); i++)

int a[200010];
int b[200010];

int main() {
	long long n;
	long long x,m;
	long long ans;
	long long  p,p_max,p_round;
	long long ansm;
	long long mm,mn;

	cin >> n >> x >> m ;
	rep(i, m) a[i]=0;
	rep(i, m) b[i]=-1;

	p=x;
	rep(i, m){
		b[p]=i;
		p=p*p;
		p%=m;
		a[i]=p;
		if (b[p]<0){
		}else{
			p_max=i+1;
			p_round=i-b[p]+1;
	        if (p_round==0)p_round=1;
            break;
		}
	}
	if (n<5*p_max){
		ans=0;
		rep(i, n){
			ans+=x;
			x=x*x;
			x%=m;
		}
		cout << ans << endl;
		return 0;
	}
	ans=0;
	p=x;
	rep(i,p_max+1){
      	ans+=p;
      	p*=p;
      	p%=m;
	}
	ansm=0;
	rep(i,p_round){
      	ansm+=p;
      	p*=p;
      	p%=m;
	}
	mm=n-4*p_round;
	mm/=p_round;
	mn=n-mm*p_round;
 	ans=0;
	p=x;
	rep(i,mn){
      	ans+=p;
      	p*=p;
      	p%=m;
	}
	ans+=mm*ansm;
	cout << ans << endl;
	return 0;
}
