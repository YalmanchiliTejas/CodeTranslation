#include <bits/stdc++.h>

using namespace std;

const string Symbol[] = { "101","000000","000011","10010001","010001","000001","100101","10011010","0101","0001","110","01001","10011011","010000","0111","10011000","0110","00100","10011001","10011110","00101","111","10011111","1000","00110","00111","10011100","10011101","000010","10010010","10010011","10010000" };
const string Alphabet = " ',-.?ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string InputStr, BinaryStr,OutputStr;

bool judge(const string& tmp) {

	for (int i = 0; i < 32; i++) {
		if (Symbol[i] == tmp) {
			OutputStr += Alphabet[i];
			return true;
		}
	}
	return false;
}

void convertBinaryToString() {
	int len;
	string tmp;

	len = BinaryStr.size();
	for (int i = 0; i < len; i++) {
		tmp += BinaryStr[i];
		if (tmp.size() > 2) {
			//cout << "tmp:" << tmp << endl;
			if (judge(tmp)) {
				tmp = "";
			}
		}
	}
}

void convertStringToBinary() {
	int len;
	stringstream ss;

	len = InputStr.size();
	for (int i = 0; i < len; i++) {
		switch (InputStr[i]) {
			case ' ' :BinaryStr += "11010"; break;
			case '.' :BinaryStr += "11011"; break;
			case ',' :BinaryStr += "11100"; break;
			case '-' :BinaryStr += "11101"; break;
			case '\'':BinaryStr += "11110"; break;
			case '?' :BinaryStr += "11111"; break;
			default  :ss << bitset<5>(InputStr[i] - 'A');
					  BinaryStr += ss.str();
					  ss.clear();
					  ss.str("");
		}
	}
	//cout << "Binay:" << BinaryStr << endl;
	return;
}

int main() {

	while (getline(cin, InputStr)) {
		//cout << "Input:" << InputStr << endl;
		convertStringToBinary();
		convertBinaryToString();
		cout << OutputStr << endl;
		cin.clear();
		InputStr = BinaryStr = OutputStr = "";
	}

	return 0;
}
