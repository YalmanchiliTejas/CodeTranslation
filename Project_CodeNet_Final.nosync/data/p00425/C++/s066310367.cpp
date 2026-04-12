#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void move (vector <vector <int> >& curr, int j )
{
	int temp;

	switch (j){
		case 0: // North
			temp = curr[1][3];
			curr[1][3] = curr[0][1];
			curr[0][1] = curr[1][1];
			curr[1][1] = curr[2][1];
			curr[2][1] = temp;
			break;
		case 1: // East
			temp = curr[1][3];
			curr[1][3] = curr[1][2];
			curr[1][2] = curr[1][1];
			curr[1][1] = curr[1][0];
			curr[1][0] = temp;
			break;
		case 2: // South
			temp = curr[2][1];
			curr[2][1] = curr[1][1];
			curr[1][1] = curr[0][1];
			curr[0][1] = curr[1][3];
			curr[1][3] = temp;
			break;
		case 3: // West
			temp = curr[1][0];
			curr[1][0] = curr[1][1];
			curr[1][1] = curr[1][2];
			curr[1][2] = curr[1][3];
			curr[1][3] = temp;
			break;
		case 4: // Left
			temp = curr[1][2];
			curr[1][2] = curr[2][1];
			curr[2][1] = curr[1][0];
			curr[1][0] = curr[0][1];
			curr[0][1] = temp;
			break;
		case 5: // Right
			temp = curr[1][2];
			curr[1][2] = curr[0][1];
			curr[0][1] = curr[1][0];
			curr[1][0] = curr[2][1];
			curr[2][1] = temp;
			break;
	} // end switch
}
 	
int main()
{
	const string ope[] = { "North", "East", "South", "West", "Left", "Right" };
	const int init_pos[][4] = { {0, 5, 0, 0}, {4, 1, 3, 6}, {0, 2, 0, 0} };	//  expansion plan of dice

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

		vector< vector <int> > curr_pos (3, vector<int> (4, 0 ) );
		int i,j;

		for (i = 0; i < 3; ++i){
			for (j = 0; j < 4; ++j){
				curr_pos[i][j] = init_pos[i][j];
			} // end for
		} // end for

		int res = curr_pos[1][1];

		for (i = 0; i < n; ++i){
			getline (cin, str );
			stringstream ss (str );
			ss >> str;
			for (j = 0; j < sizeof(ope)/sizeof(ope[0]); ++j){
				if (str == ope[j] ){
					move (curr_pos, j );
					break;
				} // end if
			} // end for
			res += curr_pos[1][1];
		} // end for
		cout << res << endl;
	} // end loop
		
	return 0;
}