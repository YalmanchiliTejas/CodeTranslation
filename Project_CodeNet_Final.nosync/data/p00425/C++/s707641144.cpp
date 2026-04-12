#include <iostream>
#include <string>
using namespace std;

int h[6][6] = {
	{1,5,2,3,0,4},
	{3,1,0,5,4,2},
	{2,1,5,0,4,3},
	{4,0,2,3,5,1},
	{0,2,4,1,3,5},
	{0,3,1,4,2,5}
};

int s_to_i(string s){
	if( s == "North" ) return 0;
	if( s == "East" )  return 1;
	if( s == "West" )  return 2;
	if( s == "South" ) return 3;
	if( s == "Right" ) return 4;
	if( s == "Left" )  return 5;
	return -1;
}

void op(int dice[6], int dice_[6], string s){
	for(int i=0 ; i<6 ; i++ ){
		int j = s_to_i( s );
		dice_[i] = dice[ h[j][i] ];
	}
	for(int i=0 ; i<6 ; i++ ){
		dice[i] = dice_[i];
	}
}

int main(){
	int n;
	string s;
	
	while( cin >> n , n ){
		int dice[6] = {1,2,3,4,5,6};
		int dice_[6] = {0};
		int p=0;
		
		for(int i=0 ; i < n ; i++ ){
			cin >> s;
			op( dice , dice_ , s );
			p += dice[0];
		}
		cout << p+1 << endl;
	}
}