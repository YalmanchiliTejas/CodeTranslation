#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,ans = 0;
	int h[25];
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> h[i];
	}
	
	int largest = 0;
	for(int i = 1;i<=n;i++){
		if(h[i]>=largest){largest = h[i]; ans++;}
	}
	cout <<ans << endl;
return 0;
}