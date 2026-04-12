#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
 //Compiler version g++ 6.3.0

 int main()
 {
 	int n;
 	cin >> n;
 	int ans=1;
 	int a;
 	cin >> a;
 	for (int i = 1; i < n; i++){
 		int b;
 		cin >> b;
 		if(a<=b){
 			ans++;
 		}
 		a=max(a,b);
 	}
 	cout << ans << endl;
 }