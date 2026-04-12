#include <iostream>
#include <sstream>
using namespace std;
string toStr(int a){
	stringstream ss;
	ss<<a;
	return ss.str();
}
int main(){
	int m,n;
	while(cin>>m>>n){
		if(m==0&&n==0)break;
		bool alive[1001];
		int num=1,rem=m;
		for(int i=0;i<m;++i) alive[i]=true;
		for(int i=1;i<=n;++i){
			string s,cmp=(i%3==0||i%5==0)?"":toStr(i);
			if(i%3==0)cmp+="Fizz";
			if(i%5==0)cmp+="Buzz";
			cin>>s;
			if(rem==1) continue;
			if(s!=cmp){
				alive[num]=false;
				--rem;
			}
			do{
				num=(num+1)%m;
			}while(alive[num]==false);
		}
		for(int i=1;i<=m;++i){
			if(alive[i%m]){
				--rem;
				cout<<((i%m==0)?m:i);
				cout<<((rem==0)?"\n":" ");
			}
		}
	}
	return 0;
}