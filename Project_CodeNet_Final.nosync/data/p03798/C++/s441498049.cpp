#include <bits/stdc++.h>
using namespace std;

int N;
string s;
vector<int> a(111111);

bool solve(int L,int R){
	for(int i=0;i<N+2;i++)a[i]=0;
	a[N]=a[0]=R;
	a[1]=a[N+1]=L;
	for(int i=1;i<=N;i++){
		int x;
		x=(s[i-1]=='o' ? 1 : -1);
		if(a[i+1]==0)a[i+1]=a[i-1]*a[i]*x;
		else if(a[i+1]!=a[i-1]*a[i]*x)return false;
	}
	
	for(int i=0;i<N;i++){
		if(a[i+1]==1)cout << 'S';
		else cout << 'W';
	}
	cout << endl;
	return true;
}

int main(){
	cin >> N >> s;
	
	if(solve(1,1))return 0;
	if(solve(1,-1))return 0;
	if(solve(-1,-1))return 0;
	if(solve(-1,1))return 0;
	cout << "-1" << endl;
	return 0;
}