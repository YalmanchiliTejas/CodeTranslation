#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
	int n,ans=0,mx=0;
	cin>>n;
	vector<int>h(n);
	rep(i,n)cin>>h[i];
	rep(i,n){
	    if(h[i]>=mx){
	        ans++;
	        mx=h[i];
	    }
	}
	cout<<ans;
	return 0;
}
