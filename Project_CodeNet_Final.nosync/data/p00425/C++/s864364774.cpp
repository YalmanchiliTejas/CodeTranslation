#include <iostream>
#include <sstream>
//#include <fstream>

using namespace std;

int main()
{
	const string ope[] = { 
		"North", "East", "West", "South", "Left", "Right"
	};
	const int order[][6] = {
			{ 1, 5, 2, 3, 0, 4 }, // north[];
			{ 3, 1, 0, 5, 4, 2 }, // east[];
			{ 2, 1, 5, 0, 4, 3 }, //west[];
			{ 4, 0, 2, 3, 5, 1 }, //south[];
			{ 0, 3, 1, 4, 2, 5 }, //left[];
			{ 0, 2, 4, 1, 3, 5 } //right[];
	};

//	cut here before submit 
//	freopen ("testcase.dice3", "r", stdin );

	string str = "";
	int n;

	while (getline (cin, str ) ){
		stringstream ssn(str);
		ssn >> n;

		if (n == 0 ){
			break;
		} // end if

		int i,j,k;
		int dice[] = { 1, 2, 3, 4, 5, 6 };
		int ans[6];

		int res = dice[0];
		for (i = 0; i < n; ++i){
			getline (cin, str );
			stringstream ss (str );
			ss >> str;
			for (j = 0; j < sizeof(ope)/sizeof(ope[0]); ++j){
				if (str == ope[j] ){
					for (k = 0; k < 6; ++k){
						ans[k] = dice[order[j][k]];
					} // end for
					res += ans[0];
					for (k = 0; k < 6; ++k){
						dice[k] = ans[k];
					} // end for
					break;
				} // end if
			} // end for
		} // end for
		cout << res << endl;	
	
	} // end loop
		
	return 0;
}