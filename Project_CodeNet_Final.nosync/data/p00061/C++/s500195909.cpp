#include <vector>
#include <map>
#include <iostream>

using namespace std;
/** Problem0062 : Rank Checker **/
int main()
{
	map<int, vector<int> > num;
	
	int t1, t2, rank; char c;
	while (1) {
		cin >> t1 >> c >> t2;
		if (t1 == 0 && t2 == 0) break;
		num[t2].push_back(t1);
	}
	
	while (cin >> t1) {
		map<int, vector<int> >::iterator it = num.begin();
		for (; it != num.end(); it++) {
			vector<int> v = num[it->first];
			vector<int>::iterator it2 = v.begin();
			for (;it2 != v.end(); it2++) {
				if (*it2 == t1) {
					rank=0;
				}
			}
			rank++;
		}
		cout << rank << endl;
	}
	
	return 0;
}