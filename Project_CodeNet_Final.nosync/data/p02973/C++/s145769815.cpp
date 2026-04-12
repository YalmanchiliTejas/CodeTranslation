//AtCoder Beginner Contest 134 - E
#include<bits/stdc++.h>
#define ll long long
using namespace std;

 
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	vector<int> m;
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	m.push_back(a[0]);
	for (int i=1;i<n;i++){
		int yes=0;
		int ye=0;
		int l=0;
		int r=m.size()-1;
		
		while(r-l>=0){
			int mid=(l+r)/2;
			if (a[i]>m[mid]){
				yes=mid;
				ye=1;
				r=mid-1;
			}else if (a[i]<=m[mid]){
				l=mid+1;
			}
		}
		
		if (!ye){
			m.push_back(a[i]);
		}else{
			m[yes]=a[i];
		}
	}	
		
 
	printf("%d\n",m.size());
} 