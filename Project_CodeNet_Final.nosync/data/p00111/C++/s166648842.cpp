#include<iostream>
#include<map>
#include<string>
using namespace std;
map<char,string> e;
map<string,char> d;
std::string noToCode(int no){
std::string ans="01234";
for(int i=0;i<5;i++){
	ans[4-i]=no%2+'0';
	no=no/2;
}
return ans;
}
void setMap(){
for(int i=0;i<26;i++){
	e['A'+i]=noToCode(i);
}
e[' '] = "11010"; 
e['.'] = "11011";
e[','] = "11100";
e['-'] = "11101";
e['\'']= "11110";
e['?'] = "11111";
 d["101"] = ' ';
 d["000000"] = '\'';
 d["000011"] = ','; 
 d["10010001"] = '-'; 
 d["010001"] = '.';
 d["000001"] = '?'; 
 d["100101"] = 'A'; 
 d["10011010"] = 'B'; 
 d["0101"] = 'C';
 d["0001"] = 'D'; 
 d["110"] = 'E'; 
 d["01001"] = 'F'; 
 d["10011011"] = 'G';
 d["010000"] = 'H'; 
 d["0111"] = 'I'; 
 d["10011000"] = 'J'; 
 d["0110"] = 'K';
 d["00100"] = 'L'; 
 d["10011001"] = 'M'; 
 d["10011110"] = 'N';
 d["00101"] = 'O';
 d["111"] = 'P'; 
 d["10011111"] = 'Q'; 
 d["1000"] = 'R'; 
 d["00110"] = 'S'; 
 d["00111"] = 'T'; 
 d["10011100"] = 'U';  
 d["10011101"] = 'V'; 
 d["000010"] = 'W'; 
 d["10010010"] = 'X'; 
 d["10010011"] = 'Y'; 
 d["10010000"] = 'Z'; 
}
int main(){
setMap();
string line,put1,ans;
int p,k,size;
while(getline(cin,line)){
	put1="";
	for(int i=0;i<line.size();i++){
		put1.append(e[line[i]]);
	}
	ans="";
	p=0;
	size=put1.size();
	while(p<size){
		for(int k=3;k<9;k++){
			if(p+k>size){
				 p=size;
				 break;
			}
			line=put1.substr(p,k);
			if(d.find(line)!=d.end()){
				ans+=d[line];
				p=p+k-1;
				break;
			}
		}
		p++;
	}
	cout<<ans<<"\n";
}
}