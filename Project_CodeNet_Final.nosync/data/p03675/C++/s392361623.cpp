#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	deque<int>a(n),b;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i%2==0&&n%2==0){
			b.push_back(a[i]);
		}
		else if(i%2==1&&n%2==0){
			b.push_front(a[i]);	
		}
		else if(i%2==0&&n%2==1){
			b.push_front(a[i]);	
		}
		else if(i%2==1&&n%2==1){
			b.push_back(a[i]);	
		}
	}
	for(int i=0;i<n;i++) cout<<b[i]<<" ";
	return 0;
}