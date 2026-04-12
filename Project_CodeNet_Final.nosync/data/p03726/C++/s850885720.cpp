#include<unordered_set>
#include<set>
#include<deque>
#include<queue>
#include<map>

#include<string>
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long int llint;
#define pub push_back
#define mp make_pair
#define fir first
#define sec second
#define res resize
#define mt make_tuple
const int big=((int)1<<30);
int n,i,j,q,w,gen;
string ans="Second";
vector<int> siz;
vector<vector<int>> nod;
int make_tree(int per,int ter){
	//oya[ter]=per;
	siz[ter]=1;
	auto itr=find(nod[ter].begin(),nod[ter].end(),per);
	if(itr!=nod[ter].end()){ nod[ter].erase(itr); }
	for(auto it=nod[ter].begin();it!=nod[ter].end();it++){siz[ter]+=make_tree(ter,*it); }
	return siz[ter];
}
int main(void){
	
	cin>>n;
	if(n%2==1){ cout<<"First"<<endl;return 0; }
	siz.resize(n);
	nod.resize(n);
	for(i=1;i<n;i++){
		cin>>q>>w;q--;w--;
		nod[q].pub(w);
		nod[w].pub(q);
	}
	make_tree(-1,0);
	if(nod[0].size()==1){ nod[nod[0][0]].pub(0);siz[nod[0][0]]++;nod[0].clear();siz[0]=1; }
	for(i=0;i<n;i++){
		gen=0;
		for(j=0;j<nod[i].size();j++){
			if(siz[nod[i][j]]%2==1){gen++;}
			if(gen>=2){ 
				cout<<"First"<<endl;return 0; 
			}
		}
	}
	cout<<"Second"<<endl;
	return 0;
}
