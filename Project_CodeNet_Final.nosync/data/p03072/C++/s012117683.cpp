#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int x[n];
	int s=1;
	int xmin=0;
	for(int i=0;i<n;i++){
		cin>>x[i];
		if(i==0) xmin=x[i];
	}
	for(int i=1;i<n;i++){
		if(x[i]>=xmin){
			xmin=x[i];
			s++;
		}
	}
	cout<<s<<"\n";
	return 0;
}