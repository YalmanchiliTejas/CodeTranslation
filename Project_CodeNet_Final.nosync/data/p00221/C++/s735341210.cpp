#include <iostream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

int main()
{
	int m, n;
	list<int> players;
	string say;

	while (cin >> m >> n, m){
		
		// initialize
		players.clear();
		for (int i = 0; i < m; i++){
			players.push_back(i + 1);
		}

		list<int>::iterator player = players.begin();
		for (int i = 1; i <= n; i++){
			ostringstream stream;
			
			cin >> say;
			if (players.size() == 1) continue;

			stream << i;

			if (i % 15 == 0) if (say != "FizzBuzz") player = players.erase(player); else player++;
			else if (i % 3 == 0) if (say != "Fizz") player = players.erase(player);	else player++;
			else if (i % 5 == 0) if (say != "Buzz") player = players.erase(player); else player++;
			else if (stream.str() != say) player = players.erase(player); 
			else player++;

			if (player == players.end()) player = players.begin(); 
		}


		cout << *players.begin();
		for (list<int>::iterator it = players.begin(); ++it != players.end(); ){
			cout << " " << *it;
		}
		cout << endl;
	}
	return (0);
}