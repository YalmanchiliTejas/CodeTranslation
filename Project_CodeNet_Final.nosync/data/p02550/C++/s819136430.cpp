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
	rep(i, m) b[i]=-1;

	p=x;
	rep(i, m){
		b[p]=i;
		p=p*p;
		p%=m;
		if (b[p]>=0){
			p_max=i+1;
			p_round=i+1-b[p];
            break;
		}
	}
	if (n<2*p_max){
		p=x;
		ans=0;
		rep(i, n){
			ans+=p;
			p=p*p;
			p%=m;
		}
		cout << ans << endl;
		return 0;
	}
	ansm=0;
	rep(i,p_round){
      	ansm+=p;
		p=p*p;
		p%=m;
	}
	mm=n-2*p_max;
	mm/=p_round;
	mn=n-mm*p_round;
 	ans=mm*ansm;
	p=x;
	rep(i,mn){
      	ans+=p;
		p=p*p;
		p%=m;
	}
	cout << ans << endl;
	return 0;
}