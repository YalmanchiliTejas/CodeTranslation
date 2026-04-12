#include<bits/stdc++.h>
using namespace std;
int main(){
    long long k,a,b,i=0;
    cin>>k>>a>>b;
    if(a<=b&&k>a) {
        cout<<-1<<'\n';
        return 0;
    }
    if(k<=a) {
        cout<<1;
        return 0;
    }
    i+=(k-a)/(a-b)*2;
    if((k-a)%(a-b)==0) {
    	cout<<i+1<<'\n';
	} else {
		cout<<i+3<<'\n';
	}
	return 0;
}