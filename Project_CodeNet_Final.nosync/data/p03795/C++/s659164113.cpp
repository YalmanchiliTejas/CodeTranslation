#include<bits/stdc++.h>
using namespace std;
int N,x,y,tot,reduce;
int main(){
	cin>>N;
	reduce=N/15*200;
	tot=N*800-reduce;
	cout<<tot<<endl;
	return 0;
}