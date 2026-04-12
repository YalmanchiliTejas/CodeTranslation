#include<iostream>
#include<set>
using namespace std;
int res,start[100],endd[100],n,m;
int pass(int k,int in,set<int> a){
	int num;
	if(k==n){
//		cout<<"@#@"<<endl;
		res++;
		return 0;
	}
	for(int i=0;i<m*2;i++){
//		cout<<"k:"<<k<< "i:"<<i<<" start:"<<start[i]<<" end:"<<endd[i]<<endl;
		set<int> b=a;
		if(start[i]==in&&a.count(endd[i])==0){
			b.insert(in);
			pass(k+1,endd[i],b);
		}
	}
	return 0;
}
int main(){
	cin>>n>>m;
	set<int> a;
	a.insert(1);
	for(int i=0;i<m;i++){
		cin>>start[i*2]>>endd[i*2];
		start[i*2+1]=endd[i*2];
		endd[i*2+1]=start[i*2];
	}
	pass(1,1,a);
	cout<<res;
	return 0;
}