#include <algorithm>
#include <iostream>

using namespace std;

int main(){
	int N, S;
	while(cin >> N && N>0){
		int largest = 0;
		int smallest = 1001;
		int sum = 0;
		for (int i = 0;i<N;i++){
			cin >> S;
			largest = max(largest,S);
			smallest = min(smallest,S);
			sum += S;
		}
		sum = sum - largest;
		sum = sum - smallest;
		cout << sum /(N-2) << endl;
	}
	return 0;
}