#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main(void){
	pair<int,char> A[5];
	for(int f=0;f!=1;){
		for(int i=0,a,b;i<5;++i){
			cin>>a>>b;
			if(a==0&&b==0){f=1;break;}
			A[i].first=a+b;
			A[i].second=(char)(i+'A');
			if(i==4){
				sort(&A[0],&A[5],greater<pair<int,char> >());
				cout<<A[0].second<<" "<<A[0].first<<endl;
			}
		}
	}
	return 0;
}