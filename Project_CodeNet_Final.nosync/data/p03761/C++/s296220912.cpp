#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> s2map(string s){
	unordered_map<char, int> m_tmp;
	for(int i=0; i<s.size(); i++){
		m_tmp[s[i]]++;
	}
	return m_tmp;
}

void min_map(unordered_map<char, int> m_tmp, unordered_map<char, int> &m_min){
	for(char c = 'a'; c <= 'z'; c++){
		if(m_tmp[c] < m_min[c]) m_min[c] = m_tmp[c];
	}
}

int main(){
	int n;
	cin >> n;
	string s;
	unordered_map<char, int> m_tmp;
	unordered_map<char, int> m_min;
	cin >> s;
	m_tmp = s2map(s);
	m_min = m_tmp;
	for(int i=1; i < n; i++){
		cin >> s;
		m_tmp = s2map(s);
		min_map(m_tmp, m_min);
	}
	for (char c = 'a'; c <= 'z'; c++) {
		for(int i=0; i < m_min[c]; i++) cout << c;
	}
	return 0;
}

