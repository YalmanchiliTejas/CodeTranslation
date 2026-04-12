#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main (){
	int H,W;cin>>H>>W;
	vector<vector<char>> A(H,vector<char>(W));
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)
		{
			cin>>A.at(i).at(j);
		}
	}
	
	for(int i=0;i<H-1;i++)
	{
		for(int j=0;j<W-1;j++)
		{
			if(A[i][j]=='#'&&A[i][j+1]=='#'&&A[i+1][j]=='#')
			{
				cout<<"Impossible"<<endl;
				return 0;
			}
			
			
			if(A[i+1][j+1]=='#'&&A[i+1][j]=='#'&&A[i][j+1]=='#')
			{
				cout<<"Impossible"<<endl;
				return 0;
			}
			
		}
	}
	
	cout<<"Possible"<<endl;
   return 0;
}