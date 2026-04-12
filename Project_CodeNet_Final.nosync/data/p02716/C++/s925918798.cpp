#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int,int> P;

#define MAX_N 200005
#define INF 1000000000000000000 // 2^63 

int N;
ll a[MAX_N];

ll get_max(int l,int r,int n){
	if(n==0) return 0;
	if(l>=r || l<0 || r>N){
		// cout << "error l:" << l << " r:"<< r << " n:" << n << endl;
		return 0;
	} 
	if(r-l==1){
		// if(n!=1) cout << "error l:" << l << " r:"<< r << " n:" << n << endl;
		return a[l];
	}
	if(r-l==2){
		// if(n!=1) cout << "error l:" << l << " r:"<< r << " n:" << n << endl;
		return max(a[l],a[l+1]);
	}
	if(2*n-1 == r-l){
		ll sum=0;
		for(int i=l;i<r;i+=2){
			sum += a[i];
		}
		return sum;
	}
	int c=(l+r)/2;
	if((r-l)%2){
		ll sum1 = get_max(l,c,n/2) + get_max(c+1,r,n-n/2);
		ll sum2 = get_max(l,c,n-n/2) + get_max(c+1,r,n/2);
		ll sum3 = get_max(l,c-1,n/2) + get_max(c,r,n-n/2);
		ll sum4 = get_max(l,c+1,n-n/2) + get_max(c+2,r,n/2);
		return max(max(sum1,sum2),max(sum3,sum4));
	}else{
		ll sum1 = get_max(l,c-1,n/2) + get_max(c,r,n-n/2);
		ll sum2 = get_max(l,c,n-n/2) + get_max(c+1,r,n/2);
		return max(sum1,sum2);
	}
}

int main() {
    cin >> N;
	rep(i,N) cin >> a[i];
	cout << get_max(0,N,N/2) << endl;
    return 0;
}
