#include<set>
#include<cstdio>
#include<string>
#include<iostream>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool regularize(string &s,const set<string> &D,const set<string> &F){
	if(s[0]!='/') return false;

// cout<<'\"'<<s<<'\"'<<endl;
	string path;
	for(int i=1;i<s.length();i++){
		path+='/';
		if(D.count(path)==0) return false;
		int pre=i;
		for(;i<s.length();i++) if(s[i]=='/') break;
		string t=s.substr(pre,i-pre);
		if(t==".."){
			if(path=="/") return false;
			int j;
			for(j=(int)path.length()-2;path[j]!='/';j--);
			path.resize(j);
		}
		else if(t=="."){
			path.resize((int)path.length()-1); // 次に '/' が追加されるので, 一つ分消しておく
		}
		else{
			path+=t;
		}
	}

	if(*path.rbegin()!='/' && *s.rbegin()=='/') path+='/';

	if(F.count(path)==1){
		s=path;
		return true;
	}
	if(*path.rbegin()!='/') path+='/';
	if(D.count(path)==1 && F.count(path+"index.html")==1){
		s=path+"index.html";
		return true;
	}
	else return false;
}

int main(){
	for(int n,m;cin>>n>>m,n;){
		set<string> D,F; // 有効な directory, file の集合
		rep(_,n){
			string s; cin>>s;
			string path;
			for(int i=1;i<s.length();i++){
				path+='/';
				D.insert(path);
				int pre=i;
				for(;i<s.length();i++) if(s[i]=='/') break;
				path+=s.substr(pre,i-pre);
			}
			F.insert(path);
		}

		rep(_,m){
			string s1,s2; cin>>s1>>s2;
			bool b1=regularize(s1,D,F);
			bool b2=regularize(s2,D,F);
			cout<<(b1&&b2?s1==s2?"yes":"no":"not found")<<endl;
		}
	}

	return 0;
}