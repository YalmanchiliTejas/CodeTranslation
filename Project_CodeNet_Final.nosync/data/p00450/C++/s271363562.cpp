#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Stone
{
	int color;
	int chain;

	Stone(int color = 0, int chain = 1):color(color),chain(chain){}


};

int n;

void solve()
{
	Stone st = Stone(0,1);
	vector<Stone> vec;

	cin >> st.color;
	vec.push_back(st);

	for(int i = 2; i <= n; i++){
		cin >> st.color;

		if(i % 2 == 1){
			if(vec.back().color == st.color){
				vec.back().chain++;
			}
			else {
				vec.push_back(st);
			}
		}
		else{
			if(vec.back().color == st.color){
				vec.back().chain++;
			}
			else {
				vec.back().color = st.color;
				vec.back().chain++;
			
				if(vec.size() > 1){
					int vsize = vec.size();

					vec[vsize-2].chain += vec[vsize-1].chain;
					vec.pop_back();
				}
			}
			
		}
	}

	int ans = 0;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i].color == 0){
			ans += vec[i].chain;
		}
	}

//	cout << "************" << endl;
/*
	for(int i = 0; i < vec.size(); i++){
		for(int j = 0; j < vec[i].chain; j++)
			cout << vec[i].color << endl;
	}
*/

//	cout << "answer" << endl;
	cout << ans << endl;
		
	
}

int main(void)
{
	while(cin >> n, n)
		solve();
}