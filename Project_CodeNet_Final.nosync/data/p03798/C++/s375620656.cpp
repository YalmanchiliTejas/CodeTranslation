// D - Menagerie
#include <bits/stdc++.h>
using namespace std;

int main(){
	int N; string S; cin>>N>>S;
	S += S[0];
	vector<bool> a(N+2);
	for(int j=0; j<4; j++){
		a[0] = j/2; a[1] = j%2;
		for(int k=2; k<N+2; k++)
			a[k] = a[k-1] && S[k-1]=='o' || !a[k-1] && S[k-1]=='x'? a[k-2]: !a[k-2];
		if(a[0]==a[N] && a[1]==a[N+1]) break;
	}
	if(a[0]!=a[N] || a[1]!=a[N+1]) cout<<"-1";
	else for(int i=0; i<N; i++) cout<<(a[i]?'S':'W');
	cout<<endl;
}