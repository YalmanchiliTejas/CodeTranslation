#include <bits/stdc++.h>
using namespace std;

#define DIR (0)
#define FIL (1)
struct F{
	string name;
	vector<F*> ch;
	int type;
	F(string name,int type) : name(name), type(type) {}
	F(){};
};

void ins(F* root,string s){
	assert(s[0] == '/' );
	string now = "";
	for(int i = 1 ; i < s.size() ; i++){
		if( s[i] == '/' ){
			//cout << now << endl;
			bool ok = false;
			for(int j = 0 ; j < root->ch.size() ; j++){
				if( root->ch[j]->name == now ){
					root = root->ch[j];
					root->type = DIR;
					ok = true;
					break;
				}
			}
			if(!ok){
				(root->ch).push_back(new F(now,DIR));
				root = (root->ch).back();
			}
			now = "";
		}else now += s[i];
	}
	assert( now != "" );
	(root->ch).push_back(new F(now,FIL));
}

F* get2(F* root_,string s){
	assert(s[0] == '/' );
	string now = "";
	vector<F*> rt;
	rt.push_back(root_);
	for(int i = 1 ; i < s.size() ; i++){
		if( s[i] == '/' ){
			F *root = rt.back();
			if( now == "." ){
				now = "";
				continue;
			}
			if( now == ".." ){
				if( rt.size() == 1 ) return NULL;
				rt.pop_back();
				now = "";
				continue;
			}
			bool ok = false;
			for(int j = 0 ; j < root->ch.size() ; j++){
				if( root->ch[j]->name == now && root->ch[j]->type == DIR){
					rt.push_back(root->ch[j]);
					ok = true;
					break;
				}
			}
			if(!ok){
				return NULL;
			}
			now = "";
		}else now += s[i];
	}
	
	if( now == "." ) now = "";
	if( now == ".." ){ rt.pop_back(); now = ""; }
	if( rt.size() == 0 ) return NULL;
	F *root = rt.back();
	if( now == "" ) {
		for(int j = 0 ; j < root->ch.size() ; j++){
			if( root->ch[j]->name == "index.html" && root->ch[j]->type == FIL){
				return root->ch[j];
			}
		}
		return NULL;
	}else{
		for(int j = 0 ; j < root->ch.size() ; j++){
			if( root->ch[j]->name == now ){
				if( root->ch[j]->type == DIR ){
						root = root->ch[j];
						for(int k = 0 ; k < root->ch.size() ; k++){
							if( root->ch[k]->name == "index.html" && root->ch[k]->type == FIL){
								return root->ch[k];
							}
						}
						return NULL;
				}else{
					return root->ch[j];
				}
			}
		}
		return NULL;
	}
}

int main(){
	int n,m;
	while( cin >> n >> m && (n||m) ){
		F *root = new F("",DIR);
		for(int i = 0 ; i < n ; i++){
			string s;
			cin >> s;
			ins(root,s);
		}
		for(int i = 0 ; i < m ; i++){
			string a,b;
			cin >> a >> b;
			F* A = get2(root,a);
			F* B = get2(root,b);
			if( A == NULL || B == NULL ) cout << "not found" << endl;
			else cout << (A==B?"yes":"no") << endl;
		}
		
		
		
		
	}
}