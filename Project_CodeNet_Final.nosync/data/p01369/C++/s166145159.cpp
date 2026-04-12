#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int d=0,e=0;
	string a,b="qazxswedcvfrtgb",c="yhnmjuiklop";
	while(cin>>a){
		if(a=="#"){
			break;
		}
		for(int i=0;i<b.size();i++){
			if(a[0]==b[i]){
				e=1;
			}
		}
		for(int i=0;i<c.size();i++){
			if(a[0]==c[i]){
				e=0;
			}
		}
		for(int i=1;i<a.size();i++){
			if(e==1){
			    for(int j=0;j<c.size();j++){
				    if(a[i]==c[j]){
				    	e=0;
				    	d++;
				    }
					
				}
			}
			else if(e==0){
			    for(int j=0;j<b.size();j++){
				    if(a[i]==b[j]){
				    	e=1;
				    	d++;
				    }
				}
			}
		}
		cout<<d<<endl;
		d=0;
	}
	// your code goes here
	return 0;
}