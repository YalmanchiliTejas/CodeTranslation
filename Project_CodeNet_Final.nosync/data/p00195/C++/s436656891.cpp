#include<iostream>
#include<string>
using namespace std;
int main(){
	int best,set,s1,s2;
	bool t=true;
	while(true){
	best=0;
	for(int i=0;i<5;i++){
		cin>>s1>>s2;
		if(s1==0&&s2==0){
			t=false;
			break;
		}
		if(best<s1+s2){
			set=i;
			best=s1+s2;
		}
	}
	if(t==false)
		break;
	char z='A'+set;
	cout<<z<<" "<<best<<endl;
	}
    return 0;
}