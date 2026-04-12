#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <functional>
#include <string>
#include <stack>
#include <queue>
#include <map>

typedef long long ll;
ll mod = 1e9 + 7;
  
using namespace std;

int main()
{
	int n,k;
    string s;
	cin >> n >> s >> k;

    char c = s.at(k - 1);
 
    for(int i = 0; i < s.size(); i++)
    {
        if(s.at(i) == c)
            cout << c;
        else
        {
            cout << '*';
        }
    }
    cout << endl;

	return 0;
}