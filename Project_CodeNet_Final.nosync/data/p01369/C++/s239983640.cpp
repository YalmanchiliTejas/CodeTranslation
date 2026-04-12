#include<bits/stdc++.h>

using namespace std;

int main(){

  while(1){

	string n;
	char c;
	int count = 0;
	
	cin>>n;

	if(n == "#")
	  break;

	if(n[0] == 'q' || n[0] == 'w' || n[0] == 'e' ||
	   n[0] == 'r' || n[0] == 't' || n[0] == 'a' ||
	   n[0] == 's'||n[0] == 'd'||n[0] == 'f'||n[0] == 'g'||
	   n[0] == 'z'||n[0] == 'x'||n[0] == 'c'||n[0] == 'v'||
	   n[0] == 'v'||n[0] == 'b')
	  c = 'l';
	else
	  c = 'r';
	
	for(int i = 1;i < n.length();++i){
	  if(n[i] == 'q' || n[i] == 'w' || n[i] == 'e' ||
		 n[i] == 'r' || n[i] == 't' || n[i] == 'a' ||
		 n[i] == 's'||n[i] == 'd'||n[i] == 'f'||n[i] == 'g'||
		 n[i] == 'z'||n[i] == 'x'||n[i] == 'c'||n[i] == 'v'||n[i] == 'v'||n[i] == 'b'){
		if(c == 'r'){
		  c = 'l';
		  count++;
		}
	  }
		  
	  else{
		if(c == 'l'){
		  c = 'r';
		  count++;
		}
	  }
	  
	}
	cout<<count<<endl;
  }
  
}

