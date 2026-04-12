#include<bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c; cin>>a>>b>>c;
	int ans = a * 100 + b * 10 + c;
	cout<<(ans % 4 ? "NO\n" : "YES\n");
}
