#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split(const string &s, char c){
	vector<string> vs;
	string w;
	for(int i = 0; i < s.size(); ++i){
		if(s[i] == c){
			vs.push_back(w);
			w = "";
		}else{
			w += s[i];
		}
	}
	if(w.size() > 0){ vs.push_back(w); }
	return vs;
}

string join(const vector<string> &vs, char c){
	string s;
	for(int i = 0; i < vs.size(); ++i){ s += c + vs[i]; }
	return s;
}

string normalize(const string &s, const vector<string> &fs){
	vector<string> vs = split(s.substr(1), '/');
	vector<string> nvs;
	for(int i = 0; i < vs.size(); ++i){
		if(vs[i] == "."){
			// nothing to do
		}else if(vs[i] == ".."){
			if(nvs.empty()){ return "#"; }
			nvs.pop_back();
		}else{
			nvs.push_back(vs[i]);
			if(i + 1 == vs.size()){ continue; }
			string t = join(nvs, '/');
			vector<string>::const_iterator it =
				lower_bound(fs.begin(), fs.end(), t + "/");
			if(it == fs.end() || it->substr(0, t.size() + 1) != t + "/"){
				return "#";
			}
		}
	}
	string t = join(nvs, '/');;
	if(s[s.size() - 1] != '/' && binary_search(fs.begin(), fs.end(), t)){
		return t;
	}else if(binary_search(fs.begin(), fs.end(), t + "/index.html")){
		return t + "/index.html";
	}else{
		return "#";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	while(true){
		int n, m;
		cin >> n >> m;
		if(n == 0 && m == 0){ break; }
		vector<string> fs(n);
		for(int i = 0; i < n; ++i){ cin >> fs[i]; }
		sort(fs.begin(), fs.end());
		for(int i = 0; i < m; ++i){
			string a, b;
			cin >> a >> b;
			const string na = normalize(a, fs);
			const string nb = normalize(b, fs);
			if(na == "#" || nb == "#"){
				cout << "not found" << endl;
			}else if(na == nb){
				cout << "yes" << endl;
			}else{
				cout << "no" << endl;
			}
		}
	}
	return 0;
}