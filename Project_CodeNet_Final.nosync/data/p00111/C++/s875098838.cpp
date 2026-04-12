#include <iostream>
#include <map>
#include <algorithm>	
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

string itos (int n )
{
	string b = "";
	while (n > 0 ){
		b += (n % 2 == 0 ? '0': '1' );
		n /= 2;
	} // end while
	while (b.length() < 5 ){
		b += '0';
	} // end while
	reverse (ALL(b ) );

	return b;
} 

int main()
{
	const string code[] = { "101", "010001", "000011", "10010001", "000000", "000001" };	
	const char extra[] = { ' ', '.', ',', '-', '\'', '?' };

	const char m[] = { 'E', 'P', 'D', 'C', 'K', 'I',
						  'R', 'L', 'O', 'S', 'T', 'F',
						  'W', 'H', 'A', 'Z', 'X',
						  'Y', 'J', 'M', 'B', 'G',
						  'U', 'V', 'N', 'Q' }; 	

	const string code2[] = { "110", "111", "0001", "0101", "0110", "0111",
								"1000", "00100", "00101", "00110", "00111", "01001",
								"000010", "010000", "100101", "10010000", "10010010",
								"10010011", "10011000", "10011001", "10011010","10011011",
								 "10011100", "10011101", "10011110", "10011111"};
	map<char,string> en1;
	int i = 0;
	for (char c = 'A'; c <= 'Z'; c++,i++ ){
		en1[c] = itos (i );  
	} // end for
	for (int j = 0; j < sizeof (extra)/sizeof (extra[0] ); i++, j++ ){
		en1[extra[j]] = itos (i );
	} // end for

	map<string, char> en2;
	for (int i = 0; i < sizeof(extra )/sizeof (extra[0] ); i++ ){
		en2[code[i]] = extra[i];
	} // end for
	for (int i = 0; i < sizeof (m )/sizeof(m[0] ); i++ ){
		en2[code2[i]] = m[i];
	} // end for

	string str;
	while (getline (cin, str ) ){
		int n = str.length();
		string ans = "";
		for (int i = 0; i < n; i++ ){
			ans += en1[str[i]];
		} // end for
		int size = ans.length();

		int i = 0;
		string res = "";
		while (i < size ){
			bool found = false;
			for (int j = 3; j <= 8; j++ ){
				string curr = ans.substr(i, j );
				if (en2.find (curr ) != en2.end() ){
					res += en2[curr];
					i += j;
					found = true;
					break;
				} // end if
			} // end for
			if (!found )
				break;
		} // end while

		cout << res << endl;
	} // end while

	return 0;
}