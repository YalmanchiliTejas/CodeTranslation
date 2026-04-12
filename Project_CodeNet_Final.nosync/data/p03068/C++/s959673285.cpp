#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
    int k;
    cin>>k;
    for(int i=0;i<n;i++){
    	if(s[i]==s[k-1]){
    	}
    	else{
    			s[i]='*';
    	}
    }
	cout<<s<<endl;
	
	return 0;
}