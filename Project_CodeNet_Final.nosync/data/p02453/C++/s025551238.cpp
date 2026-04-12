#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n,q;
	int box[100000];
	int i;
	int x;
	cin>>n;
	for(i=0;i<n;i++)	cin>>box[i];
	cin>>q;
	for(i=0;i<q;i++){
		cin>>x;
		cout<<lower_bound(box,box+n,x)-box<<endl;
	}
	return 0;
}
