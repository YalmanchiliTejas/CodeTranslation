#include <bits/stdc++.h>
using namespace std;

int h,w;

int main(){
	cin >> h >> w;

	vector<string> A(h);
	
	for(int i=0;i<h;i++)
		cin >> A[i];

	vector<bool> row(h,false);
	vector<bool> col(w,false);

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(A[i][j]=='#'){
				row[i]=true;
				col[j]=true;
			}
		}
	}

	for(int i=0;i<h;i++){
		if(row[i]){
			for(int j=0;j<w;j++){
				if(col[j])
					cout << A[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}