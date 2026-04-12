#include <iostream>
#include <string>
using namespace std;
int main()
{
	string meirei;
	string iro;
	string block_iro[100];
	int yama;
	int n;
	int block[100] = {};

	cin >> n;

	while(true)
	{
		cin >> meirei;
		if (meirei == "quit" ) break;
		else if (meirei == "pop")
		{
			cin >> yama;
			block[yama - 1]--;
			cout << block_iro[yama - 1][block[yama - 1]] << endl;
			block_iro[yama-1].erase(block[yama -1]);		
		}
		else if (meirei == "push")
		{
			cin >> yama >> iro;
			block[yama - 1]++;
			block_iro[yama-1] = block_iro[yama-1] + iro ;
		}
		else if (meirei == "move")
		{
			int p1 , p2;
			cin >> p1 >> p2;
			block[p1-1]--;
			block[p2-1]++;
			block_iro[p2 - 1] = block_iro[p2 - 1] + block_iro[p1 - 1][block[p1-1]];
			block_iro[p1 - 1].erase(block[p1 - 1]);	
		}
	}

	
	return 0;
}