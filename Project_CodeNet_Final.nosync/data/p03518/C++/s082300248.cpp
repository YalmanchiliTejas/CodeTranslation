#include <bits/stdc++.h>

using namespace std;

vector <int> V;
int A[222];
int n;

int main()
{
	int i, j, t;
	
	scanf("%d", &n);
	
	for(i=1; i<=n; i++){
		scanf("%d", A+i);
	}
	
	for(i=1; i<=n; i++){
		t = 1;
		for(j=1; j<n; j++){
			if(A[j] > A[j+1]){
				for(; t<j+1; t++) V.push_back(1);
				swap(A[j], A[j+1]);
				V.push_back(n - 1);
			}
		}
		for(; t<=n; t++) V.push_back(1);
	}
	
	printf("%d\n", (int)V.size());
	
	for(int t: V) printf("%d\n", t);
	
	return 0;
}