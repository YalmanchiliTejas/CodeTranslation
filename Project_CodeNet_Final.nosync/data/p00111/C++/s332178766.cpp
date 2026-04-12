#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <sstream>
#include <cmath>
#include <climits>
#include <set>
#include <iostream>
#include <map>
#include <functional>
#include <cstdlib>
#include <numeric>
#include <queue>
#include <complex>
#include <sstream>
#include <stack>

using namespace std;

#define reep(i,f,n) for(int i=f; i<int(n); ++i)
#define rep(i,n) reep(i,0,n)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef complex<double> Point;

struct Trie
{
	char charactor;
	Trie* child[2];
	Trie(char c = '\0') : charactor(c)
	{
		rep(i, 2) child[i] = NULL;
	}
	
	void insert(const char* str, char c)
	{
		if(str[0] == '\0')
			charactor = c;
		else{
			int n = str[0] - '0';
			if(!child[n])
				child[n] = new Trie();
			child[n]->insert(str+1, c);
		}
	}
	
	pair<char, int> get(const char* str)
	{
		if(charactor != '\0')
			return make_pair(charactor, 0);
		else{
			if(str[0] == '\0' || !child[str[0]-'0'])
				return make_pair('\0', -1);
			
			pair<char, int> pci = child[str[0]-'0']->get(str+1);
			return make_pair(pci.first, pci.second+1);
		}
	}
};

void disposeTrie(Trie* t)
{
	rep(i, 2){
		if(t->child[i] != NULL){
			disposeTrie(t->child[i]);
			delete t->child[i];
			t->child[i] = NULL;
		}
	}
}

int main()
{
	const char* chas = " ',-.?ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const char* strs[] = {"101", "000000", "000011", "10010001", "010001", "000001", "100101", "10011010", "0101", "0001", "110", "01001", "10011011", "010000", "0111", "10011000", "0110", "00100", "10011001", "10011110", "00101", "111", "10011111", "1000", "00110", "00111", "10011100", "10011101", "000010", "10010010", "10010011", "10010000"};
	
	Trie root;
	rep(i, strlen(chas)){
		root.insert(strs[i], chas[i]);
	}
	
	map<char, const char*> table;
	table['A'] = "00000";
	table['B'] = "00001";
	table['C'] = "00010";
	table['D'] = "00011";
	table['E'] = "00100";
	table['F'] = "00101";
	table['G'] = "00110";
	table['H'] = "00111";
	table['I'] = "01000";
	table['J'] = "01001";
	table['K'] = "01010";
	table['L'] = "01011";
	table['M'] = "01100";
	table['N'] = "01101";
	table['O'] = "01110";
	table['P'] = "01111";
	table['Q'] = "10000";
	table['R'] = "10001";
	table['S'] = "10010";
	table['T'] = "10011";
	table['U'] = "10100";
	table['V'] = "10101";
	table['W'] = "10110";
	table['X'] = "10111";
	table['Y'] = "11000";
	table['Z'] = "11001";
	table[' '] = "11010";
	table['.'] = "11011";
	table[','] = "11100";
	table['-'] = "11101";
	table['\''] = "11110";
	table['?'] = "11111";
	
	char str[256];
	while(fgets(str, 1024, stdin)){
		char binary[2048];
		int n = strlen(str);
		if(str[n-1] == '\n')
			str[--n] = '\0';
		
		rep(i, n){
			const char* b = table[str[i]];
			rep(j, 5)
				binary[i*5+j] = b[j];
		}
		binary[n*5] = '\0';
		
		int pos = 0;
		while(pos < n*5){
			pair<char, int> pci = root.get(binary+pos);
			if(pci.first == '\0')
				break;
			putchar(pci.first);
			pos += pci.second;
		}
		putchar('\n');
	}

	disposeTrie(&root);
	return 0;
}