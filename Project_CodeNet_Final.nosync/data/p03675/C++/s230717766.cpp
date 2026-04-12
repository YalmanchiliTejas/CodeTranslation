#include<bits/stdc++.h>

using namespace std;
#define int long long
#define N 666666
int arr[N];
deque<int> q;
signed main(){
	int n;
	cin>>n;
	int f=1;//原序 
	for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);
	for(int i=1;i<=n;i++){
		if(f){
			q.push_back(arr[i]);
		}else{
			q.push_front(arr[i]);
		}
		f^=1;
	}
	if(f){
		for(int i=0;i<n;i++) cout<<q[i]<<" ";
	}else{
		for(int i=n-1;i>=0;i--) cout<<q[i]<<" ";
	}
	return 0;
}
/*
3
1 2 3
1 2 6
1 9 6
16 9 6
31 9 6
*/