#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int n,m;
string X="NGSigjsoigjhOGNsgjoIJOri";

int main(){
	while(cin>>n>>m,n||m){
		string s,t;
		vector<int> from[10000];
		string v[10000];v[0]=X;
		int cnt=1;
		rep(i,n){
			cin>>s;
			string str;
			int p=0;
			rep(j,s.size()){
				if(s[j]=='/'){
					if(j==0)continue;
					bool check=false;
					rep(k,from[p].size()){
						if(v[from[p][k]]==str){
							p=from[p][k];
							str.clear();
							check=true;
							break;
						}
					}
					if(check)continue;
					v[cnt]=str;
					from[p].push_back(cnt);
					p=cnt;
					cnt++;
					str.clear();
					continue;
				}
				str.push_back(s[j]);
			}
			v[cnt]=str;
			from[p].push_back(cnt);
			p=cnt;
			cnt++;
		}
		rep(i,m){
			vector<int> dic;
			stack<int> p,q;
			cin>>s>>t;
			string str;
			bool ok = true;
			p.push(0);
			rep(j,s.size()){
				if(s[j]=='/'){
					if(j==0)continue;
					if(str=="."){
						//if(from[p.top()].size()==0)ok=false;
						dic.push_back(p.top());
						str.clear();
						continue;
					} else if(str==".."){
						//if(from[p.top()].size()==0)ok=false;
						str.clear();
						dic.push_back(p.top());
						p.pop();
						if(p.size()<=0){
							ok=false;
							break;
						}
						dic.push_back(p.top());
						continue;
					}
					rep(k,from[p.top()].size()){
						if(v[from[p.top()][k]]==str){
							p.push(from[p.top()][k]);
							break;
						}
						if(k==from[p.top()].size()-1)ok=false;
					}
					if(!ok)break;
					str.clear();
					continue;
				}
				str.push_back(s[j]);
				if(j==s.size()-1){
					if(str=="."){
						//if(from[p.top()].size()==0)ok=false;
						dic.push_back(p.top());
						str.clear();
						continue;
					} else if(str==".."){
						//if(from[p.top()].size()==0)ok=false;
						str.clear();
						dic.push_back(p.top());
						p.pop();
						if(p.size()<=0){
							ok=false;
							break;
						}
						dic.push_back(p.top());
						continue;
					}
					rep(k,from[p.top()].size()){
						if(v[from[p.top()][k]]==str){
							p.push(from[p.top()][k]);
							break;
						}
						if(k==from[p.top()].size()-1)ok=false;
					}
					if(!ok)break;
					str.clear();
				}
			}
			if(!ok){
				cout<<"not found"<<endl;
				continue;
			}
			int z=from[p.top()].size();
			if(z||s[s.size()-1]=='/'){
					str="index.html";
					if(from[p.top()].size()==0)ok=false;
					rep(k,from[p.top()].size()){
						if(v[from[p.top()][k]]==str){
							p.push(from[p.top()][k]);
							break;
						}
						if(k==from[p.top()].size()-1)ok=false;
					}
					if(from[p.top()].size())ok=false;
					str.clear();
			}
			rep(j,dic.size()) if(dic[j]==p.top())ok=false;
			dic.clear();
			if(!ok){
				cout<< "not found" << endl;
				continue;
			}
			str.clear();
			q.push(0);
			rep(j,t.size()){
				if(t[j]=='/'){
					if(j==0)continue;
					if(str=="."){
						//if(from[p.top()].size()==0)ok=false;
						dic.push_back(q.top());
						str.clear();
						continue;
					} else if(str==".."){
						//if(from[p.top()].size()==0)ok=false;
						str.clear();
						dic.push_back(q.top());
						q.pop();
						if(q.size()<=0){
							ok=false;
							break;
						}
						dic.push_back(q.top());
						continue;
					}
					rep(k,from[q.top()].size()){
						if(v[from[q.top()][k]]==str){
							q.push(from[q.top()][k]);
							break;
						}
						if(k==from[q.top()].size()-1)ok=false;
					}
					if(!ok)break;
					str.clear();
					continue;
				}
				str.push_back(t[j]);
				if(j==t.size()-1){
					if(str=="."){
						//if(from[p.top()].size()==0)ok=false;
						dic.push_back(q.top());
						str.clear();
						continue;
					} else if(str==".."){
						//if(from[p.top()].size()==0)ok=false;
						str.clear();
						dic.push_back(q.top());
						q.pop();
						if(q.size()<=0){
							ok=false;
							break;
						}
						dic.push_back(q.top());
						continue;
					}
					rep(k,from[q.top()].size()){
						if(v[from[q.top()][k]]==str){
							q.push(from[q.top()][k]);
							break;
						}
						if(k==from[q.top()].size()-1)ok=false;
					}
					if(!ok)break;
					str.clear();
				}
			}
			if(!ok){
				cout<<"not found"<<endl;
				continue;
			}
			z=from[q.top()].size();
			if(z||t[t.size()-1]=='/'){
					str="index.html";
					if(from[q.top()].size()==0)ok=false;
					rep(k,from[q.top()].size()){
						if(v[from[q.top()][k]]==str){
							q.push(from[q.top()][k]);
							break;
						}
						if(k==from[q.top()].size()-1)ok=false;
					}
					if(from[q.top()].size())ok=false;
					str.clear();
			}
			rep(j,dic.size())if(dic[j]==q.top()) ok=false;
			if(!ok){
				cout<< "not found" << endl;
				continue;
			}
			if(p==q)cout<<"yes"<<endl;
			else cout<<"no"<<endl;
		}
	}
}