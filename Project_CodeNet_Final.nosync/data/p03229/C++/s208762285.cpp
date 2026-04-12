#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#include <iomanip>
#include <limits>
#include <string>
#define cinf(n,x) for(int i=0;i<(n);i++) cin >> x[i];
typedef long long int ll;
const long long INF = 1LL << 60;
ll mod=1e9+7;
using namespace std;

int main(){
	int n; cin >>n;
	vector<ll> a(n);
	cinf(n,a);
	ll mid=n/2;
	if(n%2==0) mid--;
	sort(a.begin(),a.end());
	vector<ll> v(n);
	v[mid]=a[0];
	for(int i=mid+2,j=1;i<n;i+=2,j+=2){
		v[i]=a[j];
	}
	for(int i=mid+1,j=n-1;i<n;i+=2,j-=2){
		v[i]=a[j];
	}
	for(int i=mid-2,j=2;i>=0;i-=2,j+=2){
		v[i]=a[j];
	}
	for(int i=mid-1,j=n-2;i>=0;i-=2,j-=2){
		v[i]=a[j];
	}
	ll cnt=0;
	for(int i=1;i<n;i++){
		cnt+=abs(v[i]-v[i-1]);
	}
	reverse(a.begin(),a.end());
	v[mid]=a[0];
	for(int i=mid+2,j=1;i<n;i+=2,j+=2){
		v[i]=a[j];
	}
	for(int i=mid+1,j=n-1;i<n;i+=2,j-=2){
		v[i]=a[j];
	}
	for(int i=mid-2,j=2;i>=0;i-=2,j+=2){
		v[i]=a[j];
	}
	for(int i=mid-1,j=n-2;i>=0;i-=2,j-=2){
		v[i]=a[j];
	}
	ll cnt1=0;
	for(int i=1;i<n;i++){
		cnt1+=abs(v[i]-v[i-1]);
	}
	cout << max(cnt,cnt1) << endl;
}