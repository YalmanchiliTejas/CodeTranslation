#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

vector<string> invertMatrix(vector<string> a){
	int h = (int)a.size();
	int w = (int)a[0].size();
	vector<string> res(w, string(h, '.'));
	rep (i, h){
		rep (j, w){
			res[j][i] = a[i][j];
		} // end rep
	} // end rep
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int H, W; cin >> H >> W;
	vector<string> a(H, string(W, '.'));
	rep (i, H) rep (j, W){
		cin >> a[i][j];
	} // end rep

	bool update = false;
	while(true){
		update = false;
		rep (cnt, 2){
			vector<string> next; next.clear();
			rep (i, (int)a.size()){
				bool ok = true;
				rep (j, (int)a[0].size()){
					if (a[i][j] == '#'){
						ok = false;
					} // end if
				} // end rep
				if (ok){
					update |= true;
				}else{
					next.push_back(a[i]);
				} // end if
			} // end rep
			a = next;
			a = invertMatrix(a);
		} // end rep
		if (!update) break;
	} // end while

	rep (i, (int)a.size()){
		cout << a[i] << endl;
	} // end rep

	return 0;
}