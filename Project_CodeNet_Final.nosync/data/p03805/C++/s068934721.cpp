#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <utility>
#include <set>

using namespace std;
typedef pair<int, int> P;

int main(int argc, char const* argv[])
{
	int n, m;
	cin >> n >> m;
	set<P> st;
	for(int i = 0; i < m; i++){
			int a, b;
			cin >> a >> b;
			st.insert(make_pair(a, b));
	}
	vector<int> vec(n);
	iota(vec.begin(), vec.end(), 1);
	int res = 0;
	do{
			if(vec[0] != 1)continue;
			for(int i = 1; i < vec.size(); i++){
					if(st.find(make_pair(vec[i - 1], vec[i])) == st.end() && st.find(make_pair(vec[i], vec[i - 1])) == st.end())break;
					if(i == vec.size() - 1)res++;
			}
	}while(next_permutation(vec.begin(), vec.end()));
	cout << res << endl;
	return 0;
}
