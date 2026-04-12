#include <cassert>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define dump(n) cout<<"# "<<#n<<'='<<(n)<<endl
#define rep(i,n) for(int i=0;i<int(n);i++)

template<typename T>
ostream& operator<<(ostream& os,const vector<T>& a){
	os<<'[';
	for(auto i=a.begin();i!=a.end();++i) os<<(i!=a.begin()?" ":"")<<*i;
	return os<<']';
}
template<typename T>
ostream& operator<<(ostream& os,const set<T>& a){
	os<<'[';
	for(auto i=a.begin();i!=a.end();++i) os<<(i!=a.begin()?" ":"")<<*i;
	return os<<']';
}

string concat(const vector<string>& ss,char sep)
{
	string res;
	rep(i,ss.size()){
		res+=ss[i];
		if(i<ss.size()-1) res+=sep;
	}
	return res;
}

string parse(const map<string,set<string>>& files,const string& path)
{
	vector<string> dirs(1,"");
	string basename;
	for(int i=0,j=1;i<path.size();i=j++)
		for(;;j++) if(j==path.size() || path[j]=='/'){
			basename=path.substr(i+1,j-(i+1));
			if(j==path.size()){
				if(basename=="" || basename=="." || basename==".."){
					if(basename==".."){
						dirs.pop_back();
						if(dirs.empty())
							throw "not found";
					}
					basename="index.html";
					if(!files.at(concat(dirs,'/')).count(basename))
						throw "not found";
					dirs.push_back(basename);
					if(files.count(concat(dirs,'/')))
						throw "not found";
					return concat(dirs,'/');
				}
				else{
					if(!files.at(concat(dirs,'/')).count(basename))
						throw "not found";
					dirs.push_back(basename);
					if(!files.count(concat(dirs,'/')))
						return concat(dirs,'/');
					else{
						if(!files.at(concat(dirs,'/')).count("index.html"))
							throw "not found";
						dirs.push_back("index.html");
						if(files.count(concat(dirs,'/')))
							throw "not found";
						return concat(dirs,'/');
					}
				}
			}
			else{
				if(basename==".")
					;
				else if(basename==".."){
					dirs.pop_back();
					if(dirs.empty())
						throw "not found";
				}
				else{
					dirs.push_back(basename);
					if(!files.count(concat(dirs,'/')))
						throw "not found";
				}
			}
			break;
		}
	assert(0);
}

int main()
{
	for(int n,m;cin>>n>>m,n|m;){
		map<string,set<string>> files;
		rep(_,n){
			string path; cin>>path;
			for(int i=0,j=1;i<path.size();i=j++)
				for(;;j++) if(j==path.size() || path[j]=='/'){
					string dirname=path.substr(0,i);
					string basename=path.substr(i+1,j-(i+1));
					files[dirname].insert(basename);
					break;
				}
		}
		
		for(int i=0;i<m;i++){
			string path1,path2; cin>>path1>>path2;
			try{
				path1=parse(files,path1);
				path2=parse(files,path2);
				cout<<(path1==path2?"yes":"no")<<endl;
			}
			catch(const char* message){
				cout<<message<<endl;
			}
		}
	}
}