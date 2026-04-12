#include <iostream>
#include<bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
   string s;
   
   getline(cin,s);
   int c1=0;
   int c2=0;
   for(int i=0;i<3;i++){
   	if(s[i]=='A'){
   		c1++;
   		
	   }
   	else if(s[i]=='B'){
   		c2++;
	   }
	else{
	}   
   }
   if(c1==3){
   	cout << "No";
   }
   else if(c2==3){
   	cout << "No";
   }
   else{
   	cout << "Yes";
   }
}



