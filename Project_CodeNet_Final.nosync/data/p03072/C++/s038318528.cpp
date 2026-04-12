#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> vectH(n);

	int max_H = 0;
	int count = 0;
	for(int i=0;i<n;++i){
		cin >> vectH[i];
		if(max_H <= vectH[i]){
			count++;
			max_H = vectH[i];
		}
	}

	cout << count << endl;

	return 0;
}
