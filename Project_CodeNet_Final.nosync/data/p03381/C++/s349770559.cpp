#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x[200000],sx[200000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i];
		sx[i]=x[i];
	}
	sort(sx,sx+n);
	for(int i=0;i<n;i++)
		cout<<(x[i]<sx[n/2]?sx[n/2]:sx[n/2-1])<<endl;
}
