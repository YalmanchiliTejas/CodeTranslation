#include <bits/stdc++.h>
using namespace std;



void print(vector<int> v){
	
	for(int i=0;i<v.size();i++){
		cout<<v[i];
	}
	//cout<<endl;
}
int jud(int x){
	
	if(x%2==0)return x/2;
	else return (3*x)+1;
}
int X;
int P_max=0;
int P_sum=0;
int cnt=0;
int m[10000001]={0};
string str= "Christmas Eve Eve Eve";

void solve(){
	
	cin>>X;
	if((X==3)||(X==5)||(X==7))cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

}


int main(){

    solve();
    return 0;
}


