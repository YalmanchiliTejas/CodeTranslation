#include <iostream>
#include <string>

using namespace std;

struct Trie {
	char value;
	bool finished;
	Trie *next[2];
	Trie() {
		value = 0;
		finished = false;
		next[0] = next[1] = NULL;
	}
};
void add(Trie *r, const char *t, char v)
{
	for (int i = 0; t[i]; i++){
		int c = t[i] - '0';
		if (!r->next[c]) r->next[c] = new Trie();
		r = r->next[c];
	}
	r->value = v;
	r->finished = true;
}

int main(void)
{
	Trie *tree = new Trie();
	char fr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";

	add(tree,"101",' ');
	add(tree,"000000",'\'');
	add(tree,"000011",',');
	add(tree,"10010001",'-');
	add(tree,"010001",'.');
	add(tree,"000001",'?');
	add(tree,"100101",'A');
	add(tree,"10011010",'B');
	add(tree,"0101",'C');
	add(tree,"0001",'D');
	add(tree,"110",'E');
	add(tree,"01001",'F');
	add(tree,"10011011",'G');
	add(tree,"010000",'H');
	add(tree,"0111",'I');
	add(tree,"10011000",'J');
	add(tree,"0110",'K');
	add(tree,"00100",'L');
	add(tree,"10011001",'M');
	add(tree,"10011110",'N');
	add(tree,"00101",'O');
	add(tree,"111",'P');
	add(tree,"10011111",'Q');
	add(tree,"1000",'R');
	add(tree,"00110",'S');
	add(tree,"00111",'T');
	add(tree,"10011100",'U');
	add(tree,"10011101",'V');
	add(tree,"000010",'W');
	add(tree,"10010010",'X');
	add(tree,"10010011",'Y');
	add(tree,"10010000",'Z');

	string str;
	while (getline(cin, str)){
		Trie *now = tree;
		for (int i = 0; i < str.length(); i++){
			for (int idx = 0; ; idx++){
				if (fr[idx] == str[i]){
					for (int j = 4; 0 <= j; j--){
						now = now->next[(idx >> j) & 1];
						if (now->finished){
							cout << now->value;
							now = tree;
						}
					}
					break;
				}
			}
		}
		cout << endl;
	}

	return 0;
}