#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n,m,a[20000],b;
	while(cin >> n >> m && (n || m)){
		for(int i = 0;i < n+m;++i){
			cin >> a[i];
		}
		sort(a,a+(n+m));
		b = a[0];
		for(int i = 0;i < n+m-1;++i){
			if(a[i+1] - a[i] > b) b = a[i+1] - a[i];
		}
		cout << b << endl;
	}
}