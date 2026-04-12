#include<iostream>

using namespace std;

int main(){
	int n; cin >> n;
	for(int i=0;i<n;i++){
		int S, Y, m; cin >> S >> Y >> m;
		int M = S;
		for(int j=0;j<m;j++){
			int s = S, y = Y;
			int kind, t; double r;
			cin >> kind >> r >> t;
			if(kind == 0){
				int risi = 0;
				for(int k=0;k<y;k++){
					risi += s * r;
					s -= t;
				}
				M = max(M, risi+s);
			} else {
				for(int k=0;k<y;k++){
					s += s * r;
					s -= t;
				}
				M = max(M, s);
			}
		}
		cout << M << endl;
	}
}