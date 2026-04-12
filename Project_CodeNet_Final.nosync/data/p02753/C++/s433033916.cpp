#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
  	int i;
  	char c;
  	cin>>s;
  	c = s[0];
  	for(i =1;i<3;i++){
      	if (c != s[i]){
          	cout<<"Yes"<<endl;
          	break;
        }
    }
  	if (i ==3){
      cout<<"No"<<endl;
    }
  	return 0;
}
