#include <iostream>
using namespace std;

int main() {
	int N;
	cin >>N;
	int max=-1 , count=0 , x;
	for(int i=0;i<N;i++){
		cin >> x;
		if(x>=max){
			count++;
			max=x;
		}
	}
	cout << count;
}