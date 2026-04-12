#include<bits/stdc++.h>
using namespace std;

int main(){
	int X, Y;
	cin >> X >> Y;
	string board[101];
	vector<bool> goodx(101, false), goody(101, false);
	for(int i = 0; i < X; i++)
	{
		cin >> board[i];
		
	}
	
	for(int i = 0; i < X; i++)
	{
		for(int j = 0; j < Y; j++)
		{
			if(board[i][j] == '#'){
				goodx[i] = true;
				goody[j] = true;
			}
		}
		
	}

	for(int i = 0; i < X; i++)
	{
		if (goodx[i]) {
			for(int j = 0; j < Y; j++)
			{
				if (goody[j]) {
					cout << board[i][j];
				}
				
			}
			cout << endl;
		}
		
	}
	return 0;
	
	
}