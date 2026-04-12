#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	vector<int> v(2);
	vector<vector<int> > s;
	int a,b,i=-1;
	while(cin>>a>>b,a||i!=-1){
		v[0]=a+b,v[1]=++i,s.push_back(v);
		if(i==4){
			sort(s.begin(),s.end());
			cout<<char('A'+s[i][1])<<" "<<s[i][0]<<endl;
			s.clear(); i=-1;
		}
	}
	return 0;
}