// 2011/05/23 Tazoe

#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int main()
{
	map<int, int> teams;

	int rnk[31];
	for(int i=0; i<=30; i++)
		rnk[i] = 0;

	while(true){
		string str;
		getline(cin, str);

		for(int i=0; i<str.size(); i++)
			if(str[i]==',')
				str[i] = ' ';

		istringstream ist(str);
		int n, c;
		ist >> n >> c;
		if(n==0&&c==0)
			break;

		teams.insert( map<int, int>::value_type( n, c ) );
		rnk[c] = 1;
	}

	for(int i=29; i>=0; i--)
		rnk[i] += rnk[i+1];

	while(!cin.eof()){
		string str;
		getline(cin, str);
		if(str.empty())
			continue;

		istringstream ist(str);
		int n;
		ist >> n;

		cout << rnk[teams[n]] << endl;
	}

	return 0;
}