#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
//#include <fstream>

using namespace std;

typedef pair<int, int> T;

int main()
{
//	cut here before submit 
//	freopen ("testcase.traffic", "r", stdin );
	string str = "";
	int n, m;

	while (1){
		cin >> n >> m;

		if (!n && !m ){
			break;
		} // end if
		queue <int> tl, tr;

		vector <T> ta (n + m + 2);

		int a,b;
		int i,j,k;

		for (i = 0; i < n; ++i){
			cin >> a;
			tl.push (a);
		} // end for

		for (j = 0;j < m; ++j){
			cin >> b;
			tr.push (b);
		} // end for

		int res = 0;

		for (k = 0; k < n + m; ++k){
			if (!tr.empty() && !tl.empty() ){
				if (tr.front() < tl.front() ){
					ta[k].first = tr.front();
					tr.pop();
				}else{
					ta[k].first = tl.front();
					tl.pop();
				} // end if
			}else if (tr.empty() && !tl.empty() ){
					ta[k].first = tl.front();
					tl.pop();
			}else if (!tr.empty() && tl.empty() ){
					ta[k].first = tr.front();
					tr.pop();
			} // end if
			ta[k].second = (k == 0 ? ta[k].first : ta[k].first - ta[k-1].first );
			res = max (res, ta[k].second );
		} // end for

		cout << res << endl;	

	} // end loop

		
	return 0;
}