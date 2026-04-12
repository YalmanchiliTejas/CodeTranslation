#include<iostream>
#include <string>
#include<vector>

using namespace std;

int main(){

	int N,count =0;
	cin >> N;
	for(int i = 1; i <= N; i++){
		count = count + 800;
		if( i%15 == 0 ){
			count = count - 200;
		}
	}
	cout << count << endl;

	return 0;

}