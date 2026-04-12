#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>


using namespace std;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}


int main(){

	int H, W;

	cin >> H >> W;

	vector<vector<char> > mas = vector<vector<char> >(H, vector<char>(W));

	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cin >> mas[i][j];
		}
	}


	vector<int> bad2 = vector<int>(H, 0);
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(mas[i][j] == '#'){
				bad2[i] = 1;
			}
		}
	}

	vector<int> bad = vector<int>(W, 0);
	for(int j=0;j<W;j++){
		for(int i=0;i<mas.size();i++){
			if(mas[i][j] == '#'){
				bad[j] = 1;
			}
		}
	}

	for(int i=0;i<mas.size();i++){
		if(bad2[i] == 0 ) continue;
		for(int j=0;j<W;j++){
			if(bad[j] == 0 ) continue;
			cout << mas[i][j];
		}
		cout << endl;
	}

	return 0;
}
