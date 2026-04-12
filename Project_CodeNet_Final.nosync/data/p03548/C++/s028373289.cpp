#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if((a%(b+c)-c)/b>=1){
		cout<<a/(b+c)+1<<endl;
	}
	else{
		cout<<(a-c)/(b+c)<<endl;
	}
}
