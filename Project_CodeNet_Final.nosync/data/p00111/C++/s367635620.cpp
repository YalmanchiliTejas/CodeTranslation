#include <iostream>
#include <string>
#include <map>
using namespace std;

string binary(int a){
	string s = "";
	while(a > 0){
		s = (char)((a%2)+'0') + s;
		a /= 2;
	}
	while(s.size() < 5)s = '0' + s;
	return s;
}

int main(){
	map<char, string> input;
	map<string, char> output;
	
	output["101"] = ' ';
    output["000000"] = '\'';
    output["000011"] = ',';
    output["10010001"] = '-';
    output["010001"] = '.';
    output["000001"] = '?';
    output["100101"] = 'A';
    output["10011010"] = 'B';
    output["0101"] = 'C';
    output["0001"] = 'D';
    output["110"] = 'E';
    output["01001"] = 'F';
    output["10011011"] = 'G';
    output["010000"] = 'H';
    output["0111"] = 'I';
    output["10011000"] = 'J';
    output["0110"] = 'K';
    output["00100"] = 'L';
    output["10011001"] = 'M';
    output["10011110"] = 'N';
    output["00101"] = 'O';
    output["111"] = 'P';
    output["10011111"] = 'Q';
    output["1000"] = 'R';
    output["00110"] = 'S';
    output["00111"] = 'T';
    output["10011100"] = 'U';
    output["10011101"] = 'V';
    output["000010"] = 'W';
    output["10010010"] = 'X';
    output["10010011"] = 'Y';
    output["10010000"] = 'Z';
	
	for(char a = 'A';a <= 'Z';a++)input[a] = binary(a-'A');
	input[' '] = "11010";
    input['.'] = "11011";
    input[','] = "11100";
    input['-'] = "11101";
    input['\''] = "11110";
    input['?'] = "11111";
	
	string s;
	while(getline(cin, s)){
		string code;
		for(int i = 0;i < s.size();i++){
			code += input[s[i]];
		}
		
		string res = "", tmp = "";
		for(int i = 0;i < code.size();i++){
			tmp += code[i];
			if(output[tmp]){
				res += output[tmp];
				tmp = "";
			}
		}
		cout << res << endl;
	}
}