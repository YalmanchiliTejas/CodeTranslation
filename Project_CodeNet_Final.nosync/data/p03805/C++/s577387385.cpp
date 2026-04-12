#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int i,j,n,m,d,ans=0;
	cin >> n >> m;
	int a[m],b[m];
	for(i=0;i<m;i++){
		cin >> a[i] >> b[i];
	}
	
	bool c[10][10];
	
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			c[i][j] = false;
		}
	}
	
	for(i=0;i<m;i++){
		c[a[i]][b[i]] = true;
		c[b[i]][a[i]] = true;
	}
	
	vector<int> v(n);
	for(i=0;i<n;i++){
		v[i] = i+1;
	}
	
	d = 0;
	for(i=0;i<n-1;i++){
		if(c[v[i+1]][v[i]]){
			d++;
		}
		if(d==n-1){
		ans +=1;
		}
	}
	
	while(next_permutation(v.begin(),v.end())){
		d = 0;
		if(v[0]!=1){
			continue;
		}
		
		for(i=0;i<n-1;i++){
			if(c[v[i+1]][v[i]]){
			d++;
			}
			if(d==n-1){
			ans +=1;
			}
		}
	}
	cout << ans << endl;
}
	