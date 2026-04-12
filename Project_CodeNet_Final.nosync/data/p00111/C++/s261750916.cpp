#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

struct Trie {
	Trie() : finish(false), code(0) {
		n[1] = n[0] = NULL;
	};
	Trie *n[2];
	bool finish;
	char code;
};

void add(Trie& t, const char *codes, char c){
	Trie *cur;
	cur = &t;
	for (int i = 0; codes[i]; i++){
		int v = codes[i] == '1';
		if (cur->n[v] == NULL){
			cur->n[v] = new Trie();
		}
		cur = cur->n[v];
	}
	cur->finish = true;
	cur->code = c;
}

int main()
{
	char E[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";

	Trie R;
	add(R,"101", ' ');
	add(R,"000000", '\'');
	add(R,"000011", ',');
	add(R,"10010001", '-');
	add(R,"010001", '.');
	add(R,"000001", '?');
	add(R,"100101", 'A');
	add(R,"10011010", 'B');
	add(R,"0101", 'C');
	add(R,"0001", 'D');
	add(R,"110", 'E');
	add(R,"01001", 'F');
	add(R,"10011011", 'G');
	add(R,"010000", 'H');
	add(R,"0111", 'I');
	add(R,"10011000", 'J');
	add(R,"0110", 'K');
	add(R,"00100", 'L');
	add(R,"10011001", 'M');
	add(R,"10011110", 'N');
	add(R,"00101", 'O');
	add(R,"111", 'P');
	add(R,"10011111", 'Q');
	add(R,"1000", 'R');
	add(R,"00110", 'S');
	add(R,"00111", 'T');
	add(R,"10011100", 'U');
	add(R,"10011101", 'V');
	add(R,"000010", 'W');
	add(R,"10010010", 'X');
	add(R,"10010011", 'Y');
	add(R,"10010000", 'Z');

	char str[4048];
	while (fgets(str, sizeof(str), stdin)){
		Trie *cur = &R;
		for (int i = 0; str[i] != '\n'; i++){
			int index;
			for (index = 0; E[index] && E[index] != str[i]; index++);
			for (int j = 4; j >= 0; j--){
				cur = cur->n[(index >> j) & 1];
				if (cur->finish){
					cout << cur->code;
					cur = &R;
				}
			}
		}
		cout << endl;
	}
	return (0);
}