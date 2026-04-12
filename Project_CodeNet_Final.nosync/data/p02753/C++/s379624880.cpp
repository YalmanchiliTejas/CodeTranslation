#include <bits/stdc++.h>
using namespace std;



int main()
{
    string a;int t=0;
	cin>>a;
	for(int i=0;i<3;i++){
		if(a[i]=='A'){
			t++;
		}
	} 
	if(t==0||t==3){
		cout<<"No"<<endl;
	}else{
		cout<<"Yes"<<endl;
	}
}