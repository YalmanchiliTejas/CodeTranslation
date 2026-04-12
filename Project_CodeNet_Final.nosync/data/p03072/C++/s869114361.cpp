#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int x,n;
int main(){
	cin>>n;
	int ans=-1;
	int t=0;
	for (int i=1;i<=n;i++) {
		cin>>x;
		if (x>=ans){
			ans = x;
			t++;
		}
	}
	cout<<t<<endl;
	return 0;
}

