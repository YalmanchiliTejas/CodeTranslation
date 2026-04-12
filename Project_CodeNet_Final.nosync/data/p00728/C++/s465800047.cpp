#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(){
	int			n;
	int			s_buf;
	int			sum;
	vector<int>	s;

	while(cin >> n){
		if(n == 0){
			break;
		}

		sum = 0;
		s_buf = 0;
		s.clear();

		for(int i = 0; i < n; i++){
			cin >> s_buf;

			s.push_back(s_buf);
		}

		sort( s.begin(), s.end() );

		for(int i = 1; i < s.size() - 1; i++){
			sum += s[i];
		}

		cout << sum / (s.size() - 2) << endl;
	}
}