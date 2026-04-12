#include<iostream>
#include<string>
using namespace std;
int main(){
	string a;
	while(true){
		int count=0;
	    cin>>a;
		if(a=="#")
			break;
		bool right=true,mae;
		for(int i=0;i<a.size();i++){
			mae=right;
			if(a[i]=='y'||a[i]=='u'||a[i]=='i'||a[i]=='o'||a[i]=='p'||a[i]=='h'||a[i]=='j'||a[i]=='k'||a[i]=='l'||a[i]=='n'||a[i]=='m'){
				right=true;
			}
			else{
				right=false;
			}
			if(i!=0&&mae!=right)
				count++;
		}
		cout<<count<<endl;
	}
	return 0;
}