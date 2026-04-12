#include "bits/stdc++.h"
using namespace std;

int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	
	string x(n,'0');
	
	x[0]='S';
	x[1]='S';
	
	for(int i=1;i<n-1;i++){
		if(s[i]=='o'&&x[i]=='S'&&x[i-1]=='S')x[i+1]='S';
		if(s[i]=='o'&&x[i]=='S'&&x[i-1]=='W')x[i+1]='W';
		if(s[i]=='o'&&x[i]=='W'&&x[i-1]=='S')x[i+1]='W';
		if(s[i]=='o'&&x[i]=='W'&&x[i-1]=='W')x[i+1]='S';
		if(s[i]=='x'&&x[i]=='S'&&x[i-1]=='S')x[i+1]='W';
		if(s[i]=='x'&&x[i]=='S'&&x[i-1]=='W')x[i+1]='S';
		if(s[i]=='x'&&x[i]=='W'&&x[i-1]=='S')x[i+1]='S';
		if(s[i]=='x'&&x[i]=='W'&&x[i-1]=='W')x[i+1]='W';
	}
	
	bool f=true;
	
	if(s[n-1]=='o'){
		if(x[n-1]=='S'&&x[n-2]==x[0])f&=true;
		else if(x[n-1]=='W'&&x[n-2]!=x[0])f&=true;
		else f=false;
	}else{
		if(x[n-1]=='S'&&x[n-2]!=x[0])f&=true;
		else if(x[n-1]=='W'&&x[n-2]==x[0])f&=true;
		else f=false;
	}
	
	if(s[0]=='o'){
		if(x[0]=='S'&&x[n-1]==x[1])f&=true;
		else if(x[0]=='W'&&x[n-1]!=x[1])f&=true;
		else f=false;
	}else{
		if(x[0]=='S'&&x[n-1]!=x[1])f&=true;
		else if(x[0]=='W'&&x[n-1]==x[1])f&=true;
		else f=false;
	}
	
	if(f){
		cout<<x<<endl;
		return 0;
	}
	
	x[0]='S';
	x[1]='W';
	
	for(int i=1;i<n-1;i++){
		if(s[i]=='o'&&x[i]=='S'&&x[i-1]=='S')x[i+1]='S';
		if(s[i]=='o'&&x[i]=='S'&&x[i-1]=='W')x[i+1]='W';
		if(s[i]=='o'&&x[i]=='W'&&x[i-1]=='S')x[i+1]='W';
		if(s[i]=='o'&&x[i]=='W'&&x[i-1]=='W')x[i+1]='S';
		if(s[i]=='x'&&x[i]=='S'&&x[i-1]=='S')x[i+1]='W';
		if(s[i]=='x'&&x[i]=='S'&&x[i-1]=='W')x[i+1]='S';
		if(s[i]=='x'&&x[i]=='W'&&x[i-1]=='S')x[i+1]='S';
		if(s[i]=='x'&&x[i]=='W'&&x[i-1]=='W')x[i+1]='W';
	}
	
	f=true;
	
	if(s[n-1]=='o'){
		if(x[n-1]=='S'&&x[n-2]==x[0])f&=true;
		else if(x[n-1]=='W'&&x[n-2]!=x[0])f&=true;
		else f=false;
	}else{
		if(x[n-1]=='S'&&x[n-2]!=x[0])f&=true;
		else if(x[n-1]=='W'&&x[n-2]==x[0])f&=true;
		else f=false;
	}
	
	if(s[0]=='o'){
		if(x[0]=='S'&&x[n-1]==x[1])f&=true;
		else if(x[0]=='W'&&x[n-1]!=x[1])f&=true;
		else f=false;
	}else{
		if(x[0]=='S'&&x[n-1]!=x[1])f&=true;
		else if(x[0]=='W'&&x[n-1]==x[1])f&=true;
		else f=false;
	}
	
	if(f){
		cout<<x<<endl;
		return 0;
	}
	
	x[0]='W';
	x[1]='S';
	
	for(int i=1;i<n-1;i++){
		if(s[i]=='o'&&x[i]=='S'&&x[i-1]=='S')x[i+1]='S';
		if(s[i]=='o'&&x[i]=='S'&&x[i-1]=='W')x[i+1]='W';
		if(s[i]=='o'&&x[i]=='W'&&x[i-1]=='S')x[i+1]='W';
		if(s[i]=='o'&&x[i]=='W'&&x[i-1]=='W')x[i+1]='S';
		if(s[i]=='x'&&x[i]=='S'&&x[i-1]=='S')x[i+1]='W';
		if(s[i]=='x'&&x[i]=='S'&&x[i-1]=='W')x[i+1]='S';
		if(s[i]=='x'&&x[i]=='W'&&x[i-1]=='S')x[i+1]='S';
		if(s[i]=='x'&&x[i]=='W'&&x[i-1]=='W')x[i+1]='W';
	}
	
	f=true;
	
	if(s[n-1]=='o'){
		if(x[n-1]=='S'&&x[n-2]==x[0])f&=true;
		else if(x[n-1]=='W'&&x[n-2]!=x[0])f&=true;
		else f=false;
	}else{
		if(x[n-1]=='S'&&x[n-2]!=x[0])f&=true;
		else if(x[n-1]=='W'&&x[n-2]==x[0])f&=true;
		else f=false;
	}
	
	if(s[0]=='o'){
		if(x[0]=='S'&&x[n-1]==x[1])f&=true;
		else if(x[0]=='W'&&x[n-1]!=x[1])f&=true;
		else f=false;
	}else{
		if(x[0]=='S'&&x[n-1]!=x[1])f&=true;
		else if(x[0]=='W'&&x[n-1]==x[1])f&=true;
		else f=false;
	}
	
	if(f){
		cout<<x<<endl;
		return 0;
	}
	
	x[0]='W';
	x[1]='W';
	
	for(int i=1;i<n-1;i++){
		if(s[i]=='o'&&x[i]=='S'&&x[i-1]=='S')x[i+1]='S';
		if(s[i]=='o'&&x[i]=='S'&&x[i-1]=='W')x[i+1]='W';
		if(s[i]=='o'&&x[i]=='W'&&x[i-1]=='S')x[i+1]='W';
		if(s[i]=='o'&&x[i]=='W'&&x[i-1]=='W')x[i+1]='S';
		if(s[i]=='x'&&x[i]=='S'&&x[i-1]=='S')x[i+1]='W';
		if(s[i]=='x'&&x[i]=='S'&&x[i-1]=='W')x[i+1]='S';
		if(s[i]=='x'&&x[i]=='W'&&x[i-1]=='S')x[i+1]='S';
		if(s[i]=='x'&&x[i]=='W'&&x[i-1]=='W')x[i+1]='W';
	}
	
	f=true;
	
	if(s[n-1]=='o'){
		if(x[n-1]=='S'&&x[n-2]==x[0])f&=true;
		else if(x[n-1]=='W'&&x[n-2]!=x[0])f&=true;
		else f=false;
	}else{
		if(x[n-1]=='S'&&x[n-2]!=x[0])f&=true;
		else if(x[n-1]=='W'&&x[n-2]==x[0])f&=true;
		else f=false;
	}
	
	if(s[0]=='o'){
		if(x[0]=='S'&&x[n-1]==x[1])f&=true;
		else if(x[0]=='W'&&x[n-1]!=x[1])f&=true;
		else f=false;
	}else{
		if(x[0]=='S'&&x[n-1]!=x[1])f&=true;
		else if(x[0]=='W'&&x[n-1]==x[1])f&=true;
		else f=false;
	}
	
	if(f){
		cout<<x<<endl;
		return 0;
	}
	
	cout<<-1<<endl;
	
}
