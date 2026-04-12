#include <cstdlib>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

struct node {
	string name;
	vector<node> children;
	bool is_file;

	node(const string& name, bool is_file):name(name), is_file(is_file) {}

	void add_file(deque<string>& path) {
		if(path.size() == 1) {
			children.emplace_back(path.front(), true);
			return;
		}

		string target = path.front();
		path.pop_front();

		for(int i = 0; i < static_cast<int>(children.size()); ++i) {
			if(children[i].name == target) {
				children[i].add_file(path);
				return;
			}
		}

		children.emplace_back(target, false);
		children.back().add_file(path);
	}

	string search(deque<string>& path, bool& used_rule) const {
		if(is_file) return path.size() ? "" : name;

		string target;
		if(path.size() == 0) {
			if(used_rule) return "";
			target = "index.html";
			used_rule = true;
		}
		else {
			target = path.front();
			path.pop_front();
		}

		if(target == ".") return search(path, used_rule);
		if(target == ".." && name.size()) return "back";

		for(int i = 0; i < static_cast<int>(children.size()); ++i) {
			if(children[i].name == target) {
				const string result = children[i].search(path, used_rule);
				if(result == "back") return search(path, used_rule);
				return result.size() ? name + '/' + result : result;
			}
		}

		return "";
	}
};

inline deque<string> split(string str, const string& delimiter, bool& used_rule) {
	deque<string> res;
	int pos = 0;
	while((pos = str.find(delimiter)) != string::npos) {
		if(pos > 0) res.push_back(str.substr(0, pos));
		str = str.substr(pos + delimiter.size());
	}

	if(str.size()) res.emplace_back(str);
	else {
		res.emplace_back("index.html");
		used_rule = true;
	}
	return res;
}

inline string search(const node& root, string s) {
	bool used_rule = false;
	deque<string> path = split(move(s), "/", used_rule);
	return root.search(path, used_rule);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	for(int n, m; cin >> n >> m && (n || m);) {
		node root("", false);

		for(int i = 0; i < n; ++i) {
			string s;
			cin >> s;

			bool disused;
			deque<string> path = split(move(s), "/", disused);
			root.add_file(path);
		}

		for(int i = 0; i < m; ++i) {
			string a, b;
			cin >> a >> b;

			a = search(root, move(a));
			b = search(root, move(b));

			if(!a.size() || !b.size()) {
				cout << "not found" << endl;
			}
			else if(a == b) {
				cout << "yes" << endl;
			}
			else {
				cout << "no" << endl;
			}
		}
	}

	return EXIT_SUCCESS;
}