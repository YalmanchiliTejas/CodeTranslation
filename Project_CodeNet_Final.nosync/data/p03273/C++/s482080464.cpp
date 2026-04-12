#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int main() {
	int H,W;
	cin>>H>>W;
	vector<string> a(H);
	vector<bool> row(H),col(W);
	rep(i,H)cin>>a[i];
	rep(i,H){
		rep(j,W){
			if(a[i][j] == '#'){
				row[i] = true;
				col[j] = true;
			}
		}
	}
	rep(i,H){
		if(row[i]){
			rep(j,W){
				if(col[j]){
					cout<<a[i][j];
				}
			}
			cout<<endl;
		}
	}
}