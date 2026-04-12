#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin >>N;
	int watchable=0;
	vector<int> H(N);//動的配列．標準入力によって確保する配列の量変化0
	for(int i=0;i<N;i++)
	{
		cin >> H[i];
	}

	for(int i=0;i<N;i++)
	{
		bool falg=true;
		for(int j=i;j>=0;j--)
		{
			if(H[i]<H[j])
				falg=false;
		}
		if(falg)
		{
			watchable++;
		}
	}
	cout << watchable << endl;
}