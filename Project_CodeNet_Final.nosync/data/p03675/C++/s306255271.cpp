#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int n,a[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	int pt=n;
	for (int i=1;i<=n;i++){
		cout << a[pt] <<
		(i==n?"\n":" ");
		if ((pt&1)==(n&1)){
			if (pt==1){
				pt++;
			}else if (pt==2){
				pt--;
			}else{
				pt-=2;
			}
		}else{
			pt+=2;
		}
	}
}