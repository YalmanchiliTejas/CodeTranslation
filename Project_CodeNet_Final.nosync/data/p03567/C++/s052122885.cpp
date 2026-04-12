#include<iostream>
#include<vector>
#include<algorithm>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
#define all(v) v.begin(),v.end()
#define pb push_back
using namespace std;

int main(){
	string s;
	cin>>s;
	bool check=false;
	rep(i,s.size()-1){
		if(s.substr(i,2)=="AC"){
			check=true;
			break;
		}
	}
	cout<<((check)?"Yes":"No")<<endl;
	return 0;
}