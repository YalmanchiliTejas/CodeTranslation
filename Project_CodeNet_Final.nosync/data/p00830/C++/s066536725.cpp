#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
using namespace std;

struct directory{
	map<string,directory*> child;
	map<string,int> file;

	explicit directory(directory *par = 0){
		child.insert(make_pair(".", this));
		child.insert(make_pair("..", par));
	}

	~directory(){
		map<string,directory*>::iterator it;
		for(it = child.begin(); it != child.end(); ++it){
			if(it->first != "." && it->first != ".."){
				delete it->second;
			}
		}
	}
};

char buf[104];
string name;

int find(directory &dir, const string &path){
	const char *p = path.c_str();
	directory *now = &dir;
	int d = 0;

	while(now && p[1]){
		sscanf(p, "/%[^/]%n", buf, &d);
		name = buf;
		p += d;

		if(now->child.count(name)){
			now = now->child[name];
			if(!*p){
				break;
			}
		}
		else if(*p == '/'){
			throw 1;
		}
		else if(now->file.count(name)){
			return now->file[name];
		}
		else{
			throw 2;
		}
	}

	if(!now){
		throw 3;
	}

	name = "index.html";
	if(now->file.count(name)){
		return now->file[name];
	}
	throw 4;
}

int main(){
	int n, m;
	string s, t;
	while(cin >> n >> m, n){
		int d = 0, id = 0;
		directory dir;

		for(int i = 0; i < n; ++i){
			cin >> s;
			const char *p = s.c_str();
			directory *now = &dir;

			while(1){
				sscanf(p, "/%[^/]%n", buf, &d);
				name = buf;
				p += d;
				if(*p != '/'){
					break;
				}

				if(!now->child.count(name)){
					now->child[name] = new directory(now);
				}
				now = now->child[name];
			}
			now->file.insert(make_pair(name, ++id));
		}

		for(int i = 0; i < m; ++i){
			try{
				cin >> s >> t;
				int x = find(dir, s), y = find(dir, t);
				puts(x == y ? "yes" : "no");
			}catch(...){
				puts("not found");
			}
		}
	}
}