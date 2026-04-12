#include <iostream>
#include <string>
#include <utility>

using namespace std;
typedef pair<int, int> pii;

pii lex_expr(const char *s, int p);
pii lex_term(const char *s, int p);

pii lex_expr(const char *s, int p){
	pii r = lex_term(s, p);
	p = r.second;
	while(s[p] == '+'){
		const pii q = lex_term(s, p + 1);
		r.first += q.first;
		r.second = p = q.second;
	}
	return r;
}
pii lex_term(const char *s, int p){
	pii r(s[p] - '0', p + 1);
	++p;
	while(s[p] == '*'){
		r.first *= s[p + 1] - '0';
		r.second = p = p + 2;
	}
	return r;
}

int solve(const char *s){
	int p = 1, result = s[0] - '0';
	while(s[p] != '\0'){
		if(s[p] == '+'){
			result += s[p + 1] - '0';
		}else{
			result *= s[p + 1] - '0';
		}
		p += 2;
	}
	return result;
}

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	int n;
	cin >> s >> n;
	const char table[] = "IMLU";
	int answer = 0;
	if(lex_expr(s.c_str(), 0).first == n){ answer |= 1; }
	if(solve(s.c_str()) == n){ answer |= 2; }
	cout << table[answer] << endl;
	return 0;
}