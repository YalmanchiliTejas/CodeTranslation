#include <bits/stdc++.h>

using namespace std;

int n,i,j,a[200005];

int main(){
	scanf("%d", &n);
	
	for(i = 0; i < n; i++)
	scanf("%d", &a[i]);
	
	vector <int> ans;
	
	if(n % 2 == 0){
		for(i = n - 1; i >= 0; i -= 2)
		ans.push_back(a[i]);
		for(i = 0; i < n; i += 2)
		ans.push_back(a[i]);
	}
	else{
		for(i = n - 1; i >= 0; i -= 2)
		ans.push_back(a[i]);
		for(i = 1; i < n; i += 2)
		ans.push_back(a[i]);	
	}
	
	for(i = 0; i < ans.size(); i++){
		if(i == 0)
		printf("%d", ans[i]);
		else
		printf(" %d", ans[i]);
	}
	printf("\n");
}
