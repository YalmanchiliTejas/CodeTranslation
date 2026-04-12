// D - Menagerie
#include <bits/stdc++.h>
using namespace std;

int main(){
	int N; string S; cin>>N>>S;

	vector<bool> q(N+1);
	for(int i=0; i<N; i++) q[i] = S[i]=='o'? true:false;
	q[N] = q[0];

	vector<bool> a(N+2);
	vector<bool> b0{1,1,0,0};
	vector<bool> b1{1,0,1,0};

	for(int i=0; i<4; i++){
		a[0] = b0[i]; a[1] = b1[i];

		for(int j=2; j<N+2; j++){

			if(a[j-1] && q[j-1]) a[j] = a[j-2];
			if(a[j-1] && !q[j-1]) a[j] = !a[j-2];
			if(!a[j-1] && q[j-1]) a[j] = !a[j-2];
			if(!a[j-1] && !q[j-1]) a[j] = a[j-2];

		}

		if(a[0]==a[N] && a[1]==a[N+1]) break;
	}

	if(a[0]==a[N] && a[1]==a[N+1])
		for(int i=0; i<N; i++) cout<<(a[i]?'S':'W');
	else cout<<"-1";
	cout<<"\n";
}
