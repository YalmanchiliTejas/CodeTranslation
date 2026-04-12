#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=a;i<b;++i)
#define for_rev(i,a,b) for(int i=a;i>=b;--i)
#define allof(a) a.begin(),a.end()
#define minit(a,b) memset(a,b,sizeof(a))
#define size_of(a) (int)a.size()

typedef vector< string > SArray;

// ver all
SArray split(string _s, string _t) {
	SArray res;
	for (int p = 0; (p = _s.find(_t)) != -1;) {
		res.push_back(_s.substr(0, p));
		_s = _s.substr(p + size_of(_t));
	}
	res.push_back(_s);
	return res;
}

int N, M;
string urls[110];
string html = "index.html";

bool exist(string& url) {
	for_(i,0,N) if (size_of(url) <= size_of(urls[i]) && urls[i].substr(0, size_of(url)) == url) return true;
	return false;
}

bool find_path(string& url) {
	for_(i,0,N) if (urls[i] == url) return true;
	return false;
}

bool check_url(string& url) {
	SArray spl = split(url.substr(1), "/");
	
	stack< string > path;
	path.push("");
	
	for_(i,0,size_of(spl)) {
		if (spl[i] == "..") {
			if (find_path(path.top())) return false;
			path.pop();
			if (!size_of(path)) return false;
		} else if (spl[i] != ".") {
			string cur = path.top();
			path.push(cur + "/" + spl[i]);
			if (!exist(path.top())) return false;
		}
	}
	
	url = path.top();
	if (url[size_of(url) - 1] == '/') url = url.substr(0, size_of(url) - 1);
	//cout << url << endl;
	
	if (size_of(url) < 10 || url.substr(size_of(url) - 10) != html) {
		if (!find_path(url)) {
			url += "/" + html;
			if (!find_path(url)) return false;
		}
	} else {
		if (!find_path(url)) {
			url += "/" + html;
			if (!find_path(url)) return false;
		}
	}
	
	return true;
}

void solve() {
	for_(i,0,N) {
		cin >> urls[i];
		//if (size_of(urls[i]) < 10 || urls[i].substr(size_of(urls[i]) - 10) != html) urls[i] += "/" + html;
	}
	
	for_(i,0,M) {
		string url1, url2; cin >> url1 >> url2;
		
		bool f1 = check_url(url1), f2 = check_url(url2);
		
		if (!f1 || !f2) cout << "not found" << endl;
		else if (url1 == url2) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}

int main() {
	while (cin >> N >> M, N) {
		solve();
	}
	return 0;
}