#include<bits/stdc++.h>
using namespace std;
int n, a[100005], x, tot;
int cmp(int a, int b){
	return a>b;
}
int main(){
	cin>>n;
	a[0]=2e9;
	for(int i=1;i<=n;i++){
		scanf("%d", &x);
		if(x<=a[tot]) a[++tot]=x;
		else *upper_bound(a+1, a+tot+1, x, cmp)=x;
	}
	cout<<tot;
} 