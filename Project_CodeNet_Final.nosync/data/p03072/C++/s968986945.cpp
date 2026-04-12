#include<iostream>
#include<string>
#include<typeinfo>
#include<vector>
#include <algorithm>
using namespace std;
int main()
{
	int N;
	cin >> N;

	vector<int> H(N);
	for(int i=0; i<N; i++){
		cin >> H.at(i);
	}

	int max=0;
	int cnt=0;
	for(int i=0; i<N; i++){
		if(H.at(i)>=max){
			cnt++;
			max = H.at(i);
		}
	}

	cout << cnt << endl;
	return 0;
}