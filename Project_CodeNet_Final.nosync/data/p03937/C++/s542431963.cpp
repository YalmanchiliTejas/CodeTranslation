#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	char** mat = new char*[n];
	bool flag = true;
	for (int i=0;i<n && flag;++i){
		mat[i] = new char[m];
		for (int j=0;j<m;++j){
			cin >> mat[i][j];
			if (i && j){
				if ((mat[i-1][j-1] == '#' || mat[i][j] == '#') && mat[i-1][j] == '#' && mat[i][j-1] == '#'){
					flag = false;
					break;
				}
			}
		}
	}
	if (flag){
		cout << "Possible" << endl;
	}
	else{
		cout << "Impossible" << endl;
	}
	return 0;
}