#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int>c;
	vector<int>d;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		c.push_back(a);
		d.push_back(a);
	}
	sort(c.begin(),c.end());
	int front,rear;
	front = c[n/2-1];
	rear = c[n/2];
	for(int i=0;i<n;i++){
		if(d[i]<=front){
			cout<<rear;
		}
		else{
			cout<<front;
		}
		cout <<endl;
	}
}