#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<set>
#include<map>
#include <string>
#define cinf(n,x) for(int i=0;i<(n);i++) cin >> x[i];
typedef long long int ll;
using namespace std;

int main(){
	int h,w; cin >>h>>w;
	vector<string> a(h);
	cinf(h,a);
	int cnt=0;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(a[i][j]=='#')cnt++;
		}
	}
	if(cnt==h+w-1)cout << "Possible" << endl;
	else cout << "Impossible" << endl;
}