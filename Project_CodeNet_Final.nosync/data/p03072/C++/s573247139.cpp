#include <bits/stdc++.h>
using namespace std;
int N,h[50],ans,mx;
int main(){
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>h[i];
		if(h[i]>=mx){ans++;mx=h[i];}
	}
	cout<<ans;
}