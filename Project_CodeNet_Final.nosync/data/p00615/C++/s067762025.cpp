#include<iostream>
#include<set>
using namespace std;
int main(){
	int a,x,y,max;
	set<int> box;
	while(cin>>x>>y,x||y){
		max=0;
		box.insert(0);
		for(int i=0;i<x;i++){
			cin>>a;
			box.insert(a);
		}
		for(int i=0;i<y;i++){
			cin>>a;
			box.insert(a);
		}
		set<int>::iterator ite=box.begin(),arr=box.begin();
		arr++;
		while(arr!=box.end()){
			if(*arr-*ite>max)
				max=*arr-*ite;
			ite++;
			arr++;
		}
		cout<<max<<endl;
		box.clear();
	}
	return 0;
}