#include<iostream>

using namespace std;

int main(){

    int r;
    int g;
    int b;

    cin >> r >> g >> b;

	int value = r*100 + g*10 + b;

	if(value%4 == 0){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}



	return 0;

}
