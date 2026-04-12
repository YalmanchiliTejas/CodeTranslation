#include <bits/stdc++.h>

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	cin>>n;
	int a[n];
	for(auto&i:a)cin>>i;
	list<int> l;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			l.push_back(1);
			if(j<n-1&&a[j]>a[j+1]){
				l.push_back(n-1);
				swap(a[j],a[j+1]);
			}
		}
		
	}
	cout<<l.size()<<endl;
	for(auto c:l) cout<<c<<endl;
}