#include <bits/stdc++.h>
using namespace std;

#define INF 15

int main(){
	int n;
	cin>>n;
	
	int sum=n/INF;
	int tot=800*n;
	
	cout<<tot-(sum*200)<<endl;
	
	return 0;
	
}