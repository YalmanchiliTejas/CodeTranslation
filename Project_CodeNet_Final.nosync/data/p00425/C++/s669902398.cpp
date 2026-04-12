#include <iostream>
#include <string>
#include <utility>

using namespace std;

int main(){
	int n;
	int total;
	string mv, N = "North", S = "South", W = "West", E = "East";
	string R = "Right", L = "Left";


	while(cin >> n){
	 	int side[7] = {0, 1, 2, 3, 4, 5, 6};
		total = 1;

		if (n == 0){
			break;
		}

		for (int i = 0; i < n; i++){
			cin >> mv;

			if(mv == N){
				swap(side[1], side[2]);
				swap(side[2], side[6]);
				swap(side[6], side[5]);
			}
			else if(mv == S){
				swap(side[1], side[5]);
				swap(side[5], side[6]);
				swap(side[6], side[2]);
			}
			else if(mv == W){
				swap(side[1], side[3]);
				swap(side[3], side[6]);
				swap(side[6], side[4]);
			}
			else if(mv == E){
				swap(side[1], side[4]);
				swap(side[4], side[6]);
				swap(side[6], side[3]);
			}
			else if(mv == R){
				swap(side[2], side[3]);
				swap(side[3], side[5]);
				swap(side[5], side[4]);
			}
			else {
				swap(side[2], side[4]);
				swap(side[4], side[5]);
				swap(side[5], side[3]);
			}

			total += side[1];
		}
		cout << total << endl;
	}
}