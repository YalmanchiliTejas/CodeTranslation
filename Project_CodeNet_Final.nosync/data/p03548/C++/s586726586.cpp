#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>
#include<map>

using namespace std;

int main(){

	int X,Y,Z;

	cin >> X >> Y >> Z;

	int size = X - 2*Z;

	int amari = size%(Y+Z);

	int count = size/(Y+Z);

	if(amari >= Y){
		count++;
	}

	cout << count << endl;


    return 0;

}
