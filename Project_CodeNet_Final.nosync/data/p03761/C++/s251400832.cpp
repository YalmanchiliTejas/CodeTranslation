#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <string.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;

    int i, j;
    int arr[26] = {0};
    vector <int> minV(26, 100000000);
    for(i = 0; i < n; i ++)
    {
    	string s;
    	cin >> s;
    	memset(arr, 0, sizeof(arr));
    	for(j = 0; j < s.length(); j ++)
    	{
    		arr[s[j] - 'a'] ++;
    	}

    	for(j = 0; j < 26; j ++)
    	{
    		minV[j] = min(minV[j], arr[j]);
    	}
    }

    for(j = 0; j < 26; j ++)
    {
    	while(minV[j] > 0)
    	{
    		minV[j] --;
    		char ch = j + 'a';
    		cout << ch;
    	}
    }
}