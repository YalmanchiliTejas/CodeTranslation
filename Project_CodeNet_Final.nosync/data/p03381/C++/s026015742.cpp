#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n+1], b[n+1];
    map<int, int> maap;
    for(int i=1; i<=n; i++) {cin >> a[i]; b[i]=a[i];}
    sort(a+1, a+n+1);
	for(int i=1; i<=n; i++){
		if(i<(n/2+1)) maap[a[i]]=a[n/2+1];
		else maap[a[i]]=a[n/2];
	}
	for(int i=1; i<=n; i++){
		cout << maap[b[i]] << endl;
	}
    return 0;
}