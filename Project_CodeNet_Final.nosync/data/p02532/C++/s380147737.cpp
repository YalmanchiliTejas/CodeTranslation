#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	string ope;
	char c;
	vector< stack< char > > st( n );
	while( cin >> ope && ope != "quit" ){
		int s;
		cin >> s;
		s -= 1;
		if( ope == "push" ){
			cin >> c;
			st[ s ].push( c );
		}else if( ope == "pop" ){
			cout << st[ s ].top() << endl;
			st[ s ].pop();
		}else if( ope == "move" ){
			int ss;
			cin >> ss;
			ss -= 1;
			st[ ss ].push( st[ s ].top() );
			st[ s ].pop();
		}
	}

	return 0;
}