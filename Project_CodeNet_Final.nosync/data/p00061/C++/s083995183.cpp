#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;


int main(void){
int num=1,tmp=1;
char camma;
map<int,int> mp;
map<int,int> mp2;

vector<int>v;
set<int>st;
vector<int>id;

for(;num!=0 || tmp!=0;){
	cin>>num;cin>>camma;cin>>tmp;
	if(num==0 && tmp==0)break;
	mp[num]=tmp;st.insert(tmp);
}
string s;
getline(cin,s);//read "\n"
while(getline(cin,s) && s.length()!=0){
	int integ=atoi(s.c_str());
	id.push_back(integ);
}

	size_t N=st.size();
	
	auto itr=st.begin();
	int cnt=N+1;mp2[*itr]=cnt;
	for(;itr!=st.end();itr++){
		mp2[*itr]=--cnt;
	}
	
	for(int i=0;i<id.size();i++){
		cout<<mp2[mp[id[i]]]<<endl;
	}

	return 0;
}
