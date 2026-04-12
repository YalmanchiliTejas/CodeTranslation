#include<bits/stdc++.h>                                                   
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define rept(i,a,b) for(int i=a; i<b; i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef vector<int> vi;

int main() {
	int h, w;
	cin >> h >> w;

	char a[101][101];
	rep(i, h){
		rep(j, w){
			cin >> a[i][j];
		}
	}

	bool h_flag[101];
	bool w_flag[101];
	rep(j, w){
	w_flag[j] = true;
		rep(i, h){
			if(a[i][j] == '#'){
				w_flag[j] = false;
				break;
			}
		}
	}

	rep(i, h){
	h_flag[i] = true;
		rep(j, w){
			if(a[i][j] == '#'){
				h_flag[i] = false;
				break;
			}
		}
	}

	rep(i, h){
		if(h_flag[i] == false){
			rep(j, w){
				if(w_flag[j] == false){
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}

    return 0;
}
