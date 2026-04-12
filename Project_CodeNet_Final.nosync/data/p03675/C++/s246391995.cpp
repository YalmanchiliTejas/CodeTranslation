#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	vector<int> a,b,c;
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		a.push_back(t);
	}
	for(int i=0;i<n;i+=2){
		b.push_back(a[i]);
	}
	for(int i=1 ;i<n;i+=2){
		c.push_back(a[i]);
	}
	reverse(c.begin(),c.end());
	for(int i=0;i<b.size();i++){
		c.push_back(b[i]);
	}
	if((n-1)%2==0)reverse(c.begin(),c.end());
	for(int i=0;i<c.size()-1;i++){
		cout<<c[i]<<' ';
	}
	cout<<c.back()<<endl;
	return 0;
}