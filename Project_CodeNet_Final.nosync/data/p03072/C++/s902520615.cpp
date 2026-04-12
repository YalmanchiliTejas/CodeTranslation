#include <bits/stdc++.h>
#define i64 long long
#define maxn (int)(1e5)
#define pii pair<int,int>
#define L first 
#define R second
#define all(x) x.begin(),x.end()
using namespace std;

int main(){
	int n; cin>>n;
	int H[n];
	for(int i=0;i<n;i++){
		cin>>H[i];
	}
	int i,j,cnt =0;
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			if(H[j]>H[i]) break;
		}
		if(j==i) cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}