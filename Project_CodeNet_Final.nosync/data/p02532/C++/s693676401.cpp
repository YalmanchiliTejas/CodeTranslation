#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
	int iCnt=0,iNum=0,iPointer1=0,iPointer2=0;
	string strBlockcol,strWay,strMove;

	vector< stack<string> > Stackblocks(1000);
	vector<string> vPopblocks(1000);

	cin >> iNum;

	while( 1 ){
		cin >> strWay;
		if( strWay == "quit" ){ break; }
		else if( strWay == "push" ){
			cin >> iPointer1;
			for( int i=1;i<=iNum;i++ ){
				if( i == iPointer1 ){
					cin >> strBlockcol;
					Stackblocks[i].push(strBlockcol);
				}
			}
		}
		else if( strWay == "pop" ){
			cin >> iPointer1;
			for( int i=1;i<=iNum;i++ ){
				if( i == iPointer1 ){
					vPopblocks[iCnt] = Stackblocks[i].top();
					Stackblocks[i].pop();
					iCnt++;
				}
			}
		}
		else if( strWay == "move" ){
			cin >> iPointer1;
			cin >> iPointer2;
			strMove = Stackblocks[iPointer1].top();
			Stackblocks[iPointer2].push(strMove);
			Stackblocks[iPointer1].pop();
		}
	}

	if( iCnt == 0 ){ exit(0); }
	else{
		for( int i=0;i<iCnt;i++ ){
			cout << vPopblocks[i] << endl;
		}
	}

	Stackblocks.clear();
	vPopblocks.clear();

	return 0;
}