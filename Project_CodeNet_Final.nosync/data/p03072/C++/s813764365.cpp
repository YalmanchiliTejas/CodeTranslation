#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	std::vector<int> H;
	for( int ii = 0; ii < N; ++ii ){
		int tmp;
		cin >> tmp;
		H.push_back(tmp);
	}
	
	//---------
	
	int accomodation = 1;
	int maxH = H[0];
	for( int ii = 1; ii < N ; ++ii ){
		if(maxH <= H[ii]){
			++accomodation;
			maxH = H[ii];
		}
	}

	cout << accomodation << endl;
	
	return 0;
}