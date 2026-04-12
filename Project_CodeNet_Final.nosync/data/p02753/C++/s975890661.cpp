#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
  	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> s;

	int x = 0;
	for (auto a : s)
    {
        if (a == 'A')
            x++;
    }

    if (x != 3 && x != 0)
        cout << "Yes";
    else
        cout << "No";

	return 0;
}
