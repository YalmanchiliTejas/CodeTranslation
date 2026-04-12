#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <sstream>
 
using namespace std;    


char getOpp(char c) {
    if (c == 'S')
	return 'W';
    else
	return 'S';
}

char getNext(char sc, char tc, char nc) {
    if (sc == 'o') {
	if (tc == 'S') {
	    return nc;
	} else {
	    return getOpp(nc);
	}
    } else {
	if (tc == 'S') {
	    return getOpp(nc);
	} else {
	    return nc;
	}
    }
    
}

string getAnimals(string &s, char first, char second, char last, int len)
{
    string t(len, '*');
    t[0] = first;
    t[1] = second;

    for (int i = 2; i < len; i++) {
	t[i] = getNext(s[i - 1], t[i - 1], t[i - 2]);
    }
    
    //cout << t << endl;
    if (last == t[len - 1] && getNext(s[len - 1], t[len - 1], t[len - 2]) == t[0]) {
	return t;
    } else {
	return "";
    }
    
}

int main(void){
    string s;
    string line;
    stringstream ss;
    int n;
    getline(cin, line);
    ss.str(line);
    ss >> n;
    
    getline(cin, s);
    int len = s.length();

    
    string t;

    string comb = "SW";
    for (int i = 0; i < comb.length(); i++) {
	for (int j = 0; j < comb.length(); j++) {
	    t = getAnimals(s, comb[i], comb[j], getNext(s[0], comb[i], comb[j]), len);
	    if (t != "") {
		goto result;
	    }
	}
    }
    
 result:
    if (t != "") {
	cout << t << endl;
    } else {
	cout << -1 << endl;
    }
 
    return 0;
}
