#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


struct S{
	string name;
	int point;
	bool operator<(const S& a)const{return point>a.point;}
}s[10];

int main(){
	int n;
	if(!(cin>>n&&n))return 0;
	while(1){
		for(int i=0;i<n;i++){
			cin>>s[i].name;
			int a,b,c;
			cin>>a>>b>>c;
			s[i].point=a*3+c;
		}
		stable_sort(s,s+n);
		for(int i=0;i<n;i++){
			cout<<s[i].name<<','<<s[i].point<<endl;
		}
		if(cin>>n&&n)cout<<endl;
		else break;
	}
	return 0;
}