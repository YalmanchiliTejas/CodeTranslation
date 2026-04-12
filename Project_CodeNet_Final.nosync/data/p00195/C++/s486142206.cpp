#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define F first
#define S second
typedef pair<int,int> pii;
int main(){
	vector<pii> v(5);
	while(cin>>v[0].F,v[0].F){
		int t;
		cin>>t;
		v[0].F+=t;
		v[0].S=0;
		for(int i=1;i<5;i++){
			cin>>t;v[i].F=t;
			cin>>t;v[i].F+=t;
			v[i].S=i;
		}
		sort(v.begin(),v.end());
		char r='A'+v[4].S;
		cout<<r<<" "<<v[4].F<<endl;
	}
}