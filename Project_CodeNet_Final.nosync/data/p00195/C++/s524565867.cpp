#include<iostream>
#include<vector>
#include<cmath>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int main(){
	vector<int> sell;
	int num1,num2;
	while(1){
		cin>>num1>>num2;
		if(num1==0 && num2==0)break;
		sell.push_back(num1+num2);
		rep(i,4){
			cin>>num1>>num2;
			sell.push_back(num1+num2);
		}
		int ansnum=0,anssum=0;
		for(int i=0;i<sell.size();i++){
			if(sell[i]>anssum){
				anssum=sell[i];
				ansnum=i;
			}
		}
		cout<<(char)(ansnum+'A')<<" "<<anssum<<endl;
		while(!sell.empty()){
			sell.pop_back();
		}
	}
	return 0;
}