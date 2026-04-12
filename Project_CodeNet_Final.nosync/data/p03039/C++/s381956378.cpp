#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define ff first
#define ss second
#define int long long
#define boost ios::sync_with_stdio(false);cin.tie(nullptr)
#include "string"


const int N = 5e5 + 5;
const int M = 1e9 + 7;
int mod(int m){
   m%=M;
   return (m+M)%M;
}

int power(int x,int y) {
   int res = 1;
   x = mod(x);
   while (y > 0) {
      if (y & 1)
         res =mod(res*x);
      y = y>>1;
      x = mod(x*x);
   }
   return mod(res);
}

int f[N],invf[N];
void fact(){
   f[0]=f[1]=1;
   for(int i=2;i<N;i++)
      f[i]=mod(f[i-1]*i);

   invf[N-1]=power(f[N-1],M-2);
   for(int i=N-1;i>0;i--)
      invf[i-1]=mod(invf[i]*i);

}

int nCr(int n,int r) {
   if(r>n)
      return 0;
   int ans = f[n];
   ans = mod(ans*invf[n-r]);
   ans = mod(ans*invf[r]);
   return ans;
}

int nPr(int n,int r) {
   if(r>n)
      return 0;
   int ans = f[n];
   ans = mod(ans*invf[n-r]);
   return ans;
}

int32_t main() {
	boost;
	fact();
	int n, m, k;
	cin >> n >> m >> k;

	int d = 0;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			int tt = i*(i+1)/2;
			tt *= m;
			d += i*i*m - tt;
			tt = j*(j + 1)/2;
			tt *= n;
			d += j*j*n - tt;
		}
	}
	d = mod(d);
	int ans = mod(nCr(n*m-2,k-2)*d);
	cout<<ans<<endl;	
}