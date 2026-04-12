#include <iostream>
#include <list>

using namespace std;

#define W (0)
#define B (1)

int main(void)
{
	while (1){
		list<pair<int, int> > st;
		pair<int, int> add;
		int n;
		
		cin >> n;
		if (n == 0)break;
		cin >> add.first;
		add.second = 1;
		st.push_back(add);
		for (int i = 2; i <= n; i++){
			int s;
			cin >> s;
			if (i % 2 == 1){
				if (st.back().first == s){
					st.back().second++;
				}
				else {
					add.first = s;
					add.second = 1;
					st.push_back(add);
				}
			}
			else {
				if (st.back().first == s){
					st.back().second++;
				}
				else {
					if (st.size() == 1){
						st.back().first = s;
						st.back().second++;
					}
					else {
						int c = st.back().second;
						st.pop_back();
						st.back().second += c + 1;
					}
				}
			}
		}
		
		list<pair<int, int> >::iterator it;
		int count = 0;
		for (it = st.begin(); it != st.end(); it++){
			if (it->first == W){
				count += it->second;
			}
		}
		
		cout << count << endl;
	}
	return (0);
}