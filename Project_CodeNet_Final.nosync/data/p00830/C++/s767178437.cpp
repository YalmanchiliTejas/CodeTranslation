#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <stack>
using namespace std;


struct directory{
	set<string> file;
	map<string,directory*> child;

	directory(directory *par = 0){
		child.insert( make_pair(".", this) );
		child.insert( make_pair("..", par) );
	}

	~directory(){
		map<string,directory*>::iterator it;
		for(it = child.begin(); it != child.end(); ++it){
			if( it->first != "." && it->first != ".." )
				delete it->second;
		}

		file.clear();
		child.clear();
	}
};


directory *root;

char name[106];


set<string>::iterator find(string path_string){
	const char *path = path_string.c_str() + 1;

	set<string>::iterator it_s;
	map<string,directory*>::iterator it_m;

	directory *cur = root;
	int d = 0;
	while(*path != '\0'){
		sscanf(path, "%[^/]%n", name, &d);
		path += d;
		bool dir = false;

		if( *path == '/' ){
			dir = true;
		}
		else{
			it_s = cur->file.find(name);
			if( it_s == cur->file.end() ){
				it_m = cur->child.find(name);
				if( it_m == cur->child.end() ){
					throw 4;
				}
				dir = true;
			}
			else{
				return it_s;
			}
		}
		
		if( dir ){
			it_m = cur->child.find(name);
			if( it_m == cur->child.end() ){
				throw 1;
			}
			
			cur = it_m->second;
			
			if( *path == '/' ){
				++path;
			}
		}
	}

	it_s = cur->file.find("index.html");
	if( it_s == cur->file.end() ) throw 5;
	return it_s;
}


int main(){
	int n, m;
	string path_string;
	string path1, path2;
	
	map<string,directory*>::iterator it_m;

	while( cin >> n >> m, n != 0 ){
		root = new directory;

		for(int i = 0; i < n; ++i){
			cin >> path_string;
			const char *path = path_string.c_str() + 1;

			directory *cur = root;
			int d = 0;
			while(true){
				sscanf(path, "%[^/]%n", name, &d);
				path += d;
				if( *path == '/' ){
					++path;

					it_m = cur->child.find(name);
					if( it_m == cur->child.end() ){
						it_m = cur->child.insert( make_pair(name, new directory(cur)) ).first;
					}
					cur = it_m->second;
				}
				else{
					cur->file.insert(name);
					break;
				}
			}
		}

		root->child.erase("..");

		for(int i = 0; i < m; ++i){
			try{
				cin >> path1 >> path2;

				set<string>::iterator p1, p2;
				p1 = find(path1);
				p2 = find(path2);

				if( p1 == p2 ){
					cout << "yes\n";
				}
				else{
					cout << "no\n";
				}
			}
			catch(int){
				cout << "not found\n";
			}
		}
		
		delete root;
	}
}