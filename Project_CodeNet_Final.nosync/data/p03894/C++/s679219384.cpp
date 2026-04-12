#include<bits/stdc++.h>
using namespace std;

int A[100105];

int main(){
	int n,m,k;
	cin >> n >> m;
	vector<int> v(m),v2(m);
	for(int i=0;i<m;i++){
		cin >> v[i] >> v2[i];
		v[i]--, v2[i]--;
	}
	
	set<int> se;
	vector<int> v3(n);
	
	int pos=0;
	A[0]=A[1]=1;
	for(int i=0;i<m;i++){
		if(pos==v[i])
			pos = v2[i];
		else if(pos == v2[i])
			pos = v[i];
		
		swap(A[v[i]], A[v2[i]]);
		if(pos-1 >= 0)
			A[pos-1] = 1;
		if(pos+1 < n){
			A[pos+1] = 1;
		}
	}
	
	int ans=0;
	for(int i=0;i<n;i++){
		if(A[i])
			ans++;
	}
	
	cout << ans << endl;
	return 0;
}