#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<math.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i = 0; i < n; i++)
#define INF (long long)(1e18)
#define MOD (int)(1e9+7)
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)
#define yn(f) (f?"Yes":"No")
#define YN(f) (f?"YES":"NO")s
#define MAX 100100

int A[MAX], B[MAX];
signed main(){
	cout<<fixed<<setprecision(7);
	
	int n, a, t, ans = 0;
	
	cin>>n;
	// cout<<n<<endl;
	for(int i = 0; i < n; i++){
		cin>>A[i];
		
	}
	
	sort(A,A+n);
	// for(int i = 0; i < n; i++){
		// cout<<A[i]<<endl;
	// }
	t = n/2;
	B[t] = A[0];
	for(int k = 1, a = A[0], b = A[0], i = 1, j = n - 1, x = 1; k < n; k++){
		if(x%2==0){
			if(k >= n-1){
				if(abs(a-A[i]) <= abs(b-A[i])){
				ans += abs(b-A[i]);
				b = A[i];
				
				} else {
				ans += abs(a-A[i]);
				a = A[i];
				}
				continue;
			}
			if(k%2){
			// if(abs(a-A[i]) <= abs(b-A[i])){
				ans += abs(b-A[i]);
				b = A[i];
				
			} else {
				ans += abs(a-A[i]);
				a = A[i];
			}
			i++;
		} else{
			// if(abs(a-A[j]) <= abs(b-A[j])){
				if(k >= n-1){
					 if(abs(a-A[j]) <= abs(b-A[j])){
					ans += abs(b-A[j]);
					b = A[j];
				} else {
				
					ans += abs(a-A[j]);
					a = A[j];
				}
				continue;
				}
			if(k%2){
				ans += abs(b-A[j]);
				b = A[j];
			} else {
				
				ans += abs(a-A[j]);
				a = A[j];
			}
			j--;
		}
		if(k%2==0)x++;
		// cout<<a<<" "<<b<<endl;
	}
	// for(int i = 1, j = n-1, x = 1, count = 1; count < n;count++){//cout<<i<<" "<<j<<" "<<x<<" "<<A[i]<<" "<<endl;
		// if(x%2==0){
			// if(count%2==0){
			// B[t+x] = A[i];
			// } else {
			// B[t+(x*(-1))] = A[i];
			// }
			// i++;
		// } else{
			// if(count%2==0){
			// B[t+x] = A[j];
			// } else {
			// B[t+(x*(-1))] = A[j];
			// }
			// j--;
		// }
		// if(count%2==0)x++;
	// }
	cout<<ans<<endl;
	
	return 0;
}