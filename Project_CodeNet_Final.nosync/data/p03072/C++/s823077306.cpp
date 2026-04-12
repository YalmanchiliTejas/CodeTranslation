#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main(){
	int n,ans=1,h,mah;
	cin>>n>>mah;
	for(int i=1;i<n;i++){
		cin>>h;
		if(h>=mah){
			ans++;
			mah=h;
		}
	}
	cout<<ans<<endl;
	return 0;
}