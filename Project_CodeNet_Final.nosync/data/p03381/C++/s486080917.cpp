#include<bits/stdc++.h>
using namespace std;
#define ran 200020
int n;
pair<int,int> a[ran];
int b[ran];
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i].first);
		a[i].second = i;
	}
	sort(a,a+n);
	for(int i=0; i<n; i++){
		b[a[i].second] = i<n/2 ? a[n/2].first : a[n/2-1].first;
	}
	for(int i=0; i<n; i++)
		printf("%d\n",b[i]);
	return 0;
}
