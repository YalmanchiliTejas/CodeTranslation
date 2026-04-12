#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int freq[26];
int main()
{
	fill(freq,freq+26,1000000000);
	int n; cin >> n;
	while(n--)
	{
		string s; cin >> s;
		int local_freq[26]; memset(local_freq,0,sizeof local_freq);
		for(const char& c : s)
			++local_freq[c-'a'];
		for(int c = 0; c < 26; c++)
			freq[c] = min(freq[c],local_freq[c]);
	}
	for(int c = 0; c < 26; c++)
		for(int t = 0; t < freq[c]; t++)
			cout<<(char)(c+'a');

	return 0;
}