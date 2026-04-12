#include<iostream>
#include<string>
#include<deque>
using namespace std;
int n;
int main(){
	cin>>n;
	deque<int> Q;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(i%2==0){
			Q.push_back(a);
		}
		else{
			Q.push_front(a);
		}
	}
	if(n%2==0){
		for(int i=0;i<n;i++){
			cout<<Q[i];
			if(i==n-1)
			cout<<"\n";
			else
			cout<<" ";
		}
	}
	else{
		for(int i=0;i<n;i++){
			cout<<Q[n-1-i];
			if(i==n-1){
				cout<<"\n";
			}
			else{
				cout<<" ";
			}
		}
	}
    return 0;
}