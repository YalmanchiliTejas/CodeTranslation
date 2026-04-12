#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200005];
struct node{
deque<int>v;
};

int res[200005];
int r=0;
deque<int>an,bn;
void solve(int n){
	
	if(n&1){
		for(int i=n;i>=1;i-=2){
			res[++r]=i;
		}
		for(int i=2;i<=n-1;i+=2){
			res[++r]=i;
		}
	}
	else{
		for(int i=n;i>=2;i-=2){
			res[++r]=i;
		}
		for(int i=1;i<=n-1;i+=2){
			res[++r]=i;
		}
	}
		for(int i=1;i<=r;i++){
		cout<<a[res[i]]<<" ";
	}
}
int main(){
int n;
scanf("%d",&n);
for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
	}
	if(n==1){
		printf("%d ",a[1]);
	
		return 0;
	}
	//solve(n);

		an.push_back(1);
		bn.push_front(1);
		
	for(int i=2;i<=n;i++){
if(i&1){
     an.push_back(i);
	 bn.push_front(i);
}
else{
	  bn.push_back(i);
	  an.push_front(i);
	
}
if(i==n){
	if(n&1){
		int t=bn.size()-1;
		for(int x=0;x<=t;x++){
			printf("%d ",a[bn[x]]);
			
		}
	}
	else{
			int t=an.size()-1;
		for(int x=0;x<=t;x++){
			printf("%d ",a[an[x]]);
			
		}
	}
}
		}
	
	

	
	return 0;
}