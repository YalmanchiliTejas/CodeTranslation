#include<iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int N,M;
	cin >> N>>M;

	string yoko;
	vector<vector<string>> strArray(N, vector<string>(M));

	for (int i = 0;i < N;i++)
	{
		cin >> yoko;
		for (int j = 0;j < M;j++)
		{

			if (yoko.find("#") != std::string::npos)
			{
				strArray.at(i).at(j) = yoko[j];
			}

		}
	}


	for (int j = 0;j < M;j++)
	{
		string sss;
		
		for (int i = 0;i < N;i++)
		{
			sss = sss + strArray.at(i).at(j);
		}

		if (sss.find("#") == std::string::npos)
		{
			for (int i = 0;i < N;i++)
			{
				strArray.at(i).at(j)="";
			}
		}
	}

	for (int i = 0;i < N;i++)
	{
		
		string out;

		for (int j = 0;j < M;j++)
		{

			out = out + strArray.at(i).at(j);

		}

		cout << out << endl;
	}
	

	
	return 0;


}
