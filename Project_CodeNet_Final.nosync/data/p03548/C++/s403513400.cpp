#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int LLI;

int main()
{
	int seat, person, gap, store;
	cin >> seat >> person >> gap;
	store = person + gap;
	store = seat / store;
	if( store * ( person + gap ) + gap <= seat )
		cout << store;
	else cout << store - 1;
}