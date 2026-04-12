#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL sum;
int a[3030], n, s;
LL dp[3030];
void add(LL &x, LL y){
  x += y;
  if (x >= 998244353) x -= 998244353;
}
int main(){
  	cin>>n>>s;
  	for (int i=1;i<=n;i++) cin>>a[i];
  	sum = 0;
  	for (int i=1;i<=n;i++){
    	dp[0] += 1;
      	for (int j=s; j>=a[i]; j--) add(dp[j], dp[j-a[i]]);
      	add(sum, dp[s]);
    }
  	cout<<sum<<endl;
	return 0;
}