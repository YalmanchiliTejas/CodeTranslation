#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N;
	cin >> N;
	int H[N];
	for(int i=0;i<N;i++)cin>>H[i];
	
	int maxv=0;
	int ans=0;
	for(int i=0;i<N;i++){
		if(H[i]>=maxv)ans++;
		maxv=max(maxv,H[i]);
		}	
	cout << ans<<endl;
}
