#include<bits/stdc++.h>
using namespace std;
int N, h[22];
int main(){
	cin>>N;
	for(int i = 1;i <= N; i++)cin>>h[i];
	int ans = 1;
	for(int i = 2;i <= N; i++){
		int flag = 1;
		for(int j = i - 1;j >= 1; j--){
			if(h[j] > h[i]){
				flag = 0;
				break;
			}
		}
		ans += flag;
	}
	cout<<ans<<endl;
	return 0;
}