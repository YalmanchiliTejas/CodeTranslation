#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
	
	string a,b,c;
	string d="ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";
	
	map<string,char> D;
	D["101"] = ' ';
	D["000000"] = '\'';
	D["000011"] = ','; 
	D["10010001"] = '-'; 
	D["010001"] = '.';
	D["000001"] = '?'; 
	D["100101"] = 'A'; 
	D["10011010"] = 'B'; 
	D["0101"] = 'C';
	D["0001"] = 'D'; 
	D["110"] = 'E'; 
	D["01001"] = 'F'; 
	D["10011011"] = 'G';
	D["010000"] = 'H'; 
	D["0111"] = 'I'; 
	D["10011000"] = 'J'; 
	D["0110"] = 'K';
	D["00100"] = 'L'; 
	D["10011001"] = 'M'; 
	D["10011110"] = 'N';
	D["00101"] = 'O';
	D["111"] = 'P'; 
	D["10011111"] = 'Q'; 
	D["1000"] = 'R'; 
	D["00110"] = 'S'; 
	D["00111"] = 'T'; 
	D["10011100"] = 'U';  
	D["10011101"] = 'V'; 
	D["000010"] = 'W'; 
	D["10010010"] = 'X'; 
	D["10010011"] = 'Y'; 
	D["10010000"] = 'Z';
	
	
	while(getline(cin,a)){
		b=c="";
		for(int i=0;i<a.size();i++){
			for(int j=0,k=1;k && j<32;j++){
				if(a[i]==d[j]){
					k=0;
					for(int l=16;l>=1;l/=2){
						if(j>=l)b+='1',j-=l;
						else b+='0';
					}
				}
			}
		}
		for(int i=0;i<b.size();i++){
			a="";
			for(int j=i;j<b.size();j++){
				a+=b[j];
				i=j;
				if(D[a]!=0){
					c+=D[a];
					break;
				}
			}
		}
		cout<<c<<endl;
	}
	
	return 0;
}
