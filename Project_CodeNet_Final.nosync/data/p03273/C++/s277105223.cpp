#include<iostream>
#include<vector>
using namespace std;

int main(){
	int H,W;
	cin >> H >> W;

	vector< vector< char >  > A = vector< vector< char >  >(H, vector< char >(W) );
	
	for(int i = 0; i < H; i++)
	{
		
		for(int j = 0; j < W; j++)
		{
			cin >> A[i][j];
		}
		
	}

	
	vector<int> kaigyou(H);
	for(int i = 0; i < H; i++)
	{
		
		bool flag = false;
		for(int j = 0; j < W; j++)
		{
			if(A[i][j] == '#'){
				flag = true;
			}
		}

		if(flag==false){
			kaigyou[i] = 0;
			for(int j = 0; j < W; j++)
			{
				A[i][j] = '*';
			}
		}else{
			kaigyou[i] = 1;
		}
	}
	
	for(int i = 0; i < W; i++)
	{
		
		bool flag = false;
		for(int j = 0; j < H; j++)
		{
			if(A[j][i] == '#'){
				flag = true;
			}
		}

		if(flag==false){
			for(int j = 0; j < H; j++)
			{
				A[j][i] = '*';
			}
		}
	}

	
	for(int i = 0; i < H; i++)
	{

		for(int j = 0; j < W; j++)
		{
			if(A[i][j] != '*'){
				cout << A[i][j];
			}
		}
		if(kaigyou[i]==1){
			cout << endl;
		}
		
	}
	

	return 0;

}

