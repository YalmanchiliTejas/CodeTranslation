#include<cstdio>
#include<iostream>
#include<string>
using namespace std;



int main(void){
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	int h=0;
	for(int i=0;i<s.size();i++){
        if(s[i]=='A'&&s[i+1]=='C'){
            cout<<"Yes\n";
            return 0;
        }
    }
    cout<<"No\n";
	return 0;
}
