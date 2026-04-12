#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n,ans;
	cin >> n;
	ans=n*800;
	ans=ans-(n/15*200);
	cout << ans << endl;
}