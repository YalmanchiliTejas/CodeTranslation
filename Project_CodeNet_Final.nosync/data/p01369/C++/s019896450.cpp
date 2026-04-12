#include<iostream>
#include<string>
using namespace std;

int seach(char in){
	int r;
	if(in=='a')r=1;
	else if(in=='z')r=1;
	else if(in=='q')r=1;
	else if(in=='x')r=1;
	else if(in=='s')r=1;
	else if(in=='w')r=1;
	else if(in=='c')r=1;
	else if(in=='d')r=1;
	else if(in=='e')r=1;
	else if(in=='v')r=1;
	else if(in=='f')r=1;
	else if(in=='r')r=1;
	else if(in=='b')r=1;
	else if(in=='g')r=1;
	else if(in=='t')r=1;
	
	
	else if(in=='y')r=0;
	else if(in=='h')r=0;
	else if(in=='n')r=0;
	else if(in=='m')r=0;
	else if(in=='j')r=0;
	else if(in=='u')r=0;
	else if(in=='i')r=0;
	else if(in=='k')r=0;
	else if(in=='l')r=0;
	else if(in=='o')r=0;
	else if(in=='p')r=0;
	
	return r;
}
int main(){
	string in;
	int i,r,l,total;
	while(cin>> in,in!="#"){
	l=seach(in[0]);
	total=0;
	for(int i=1;i<in.size();i++){
		r=seach(in[i]);
		if(l!=r)total++;
		l=r;
	}
	cout<<total<<endl;
	}
}