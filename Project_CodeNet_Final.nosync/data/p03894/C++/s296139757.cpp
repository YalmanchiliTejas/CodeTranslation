#include <iostream>

using namespace std;
int x[100010],a[100010],b[100010],cnt[100010] = {},y[100010];
int main(){
	int i,n,q;
	cin >> n >> q;
	x[0] = 0;
	for(i=0;i<n;i++) y[i] = i;
	for(i=0;i<q;i++){
		cnt[y[x[i]]]++;
		if(x[i]!=0) cnt[y[x[i]-1]]++;
		if(x[i]!=n) cnt[y[x[i]+1]]++;
		cin >> a[i] >> b[i]; a[i]--; b[i]--;
		int k = y[a[i]]; 
		y[a[i]] = y[b[i]]; y[b[i]] = k;
		if(x[i]==a[i]) x[i+1] = b[i];
		else if(x[i]==b[i]) x[i+1] = a[i];
		else x[i+1] = x[i];
	}
	cnt[y[x[q]]]++;
	if(x[q]!=0) cnt[y[x[q]-1]]++;
	if(x[q]!=n) cnt[y[x[q]+1]]++;
	int ans = 0;
	for(i=0;i<n;i++){
		if(cnt[i]){
			ans++;
		}
	}
	cout << ans << endl;
}