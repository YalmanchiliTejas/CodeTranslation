#include <iostream>
#include <vector>
using namespace std;

int main(){
	int H , W ;
	cin >> H >> W;
	vector <int>  A(H) , B(W);
	vector<vector<char>> C (H , vector<char> (W));
	for (int i = 0; i < H; i++){
		for (int j = 0; j < W; j++){
			cin >> C.at(i).at(j);
			if(C.at(i).at(j) == '#'){
				A.at(i) = 1;
				B.at(j) = 1;
			}
		}
	}

	for (int i = 0; i < H; ++i){
		if(A.at(i)){
			for (int j = 0; j < W; ++j) {
	     		if(B.at(j)){
					 cout << C.at(i).at(j);
				 }
    		}
			cout << endl;
		}
  	} 
}