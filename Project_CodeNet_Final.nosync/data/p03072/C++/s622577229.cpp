#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

int main(){
	int n,max=0,ans=0;
	cin>>n;
	vector<int>A(n);
	for(int i=0;i<n;i++) cin>>A[i];
	for(int i=0;i<n;i++){
		if(A[i]>=max){
			ans++;
			max=A[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}