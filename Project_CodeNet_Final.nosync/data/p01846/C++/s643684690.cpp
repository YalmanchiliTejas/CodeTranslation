#include <iostream>
#include <string>
using namespace std;

char m[10][10];
int h,w;
void decrypt(const string& s){
	h=0;w=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='/'){h++;w=0;}
		else if(s[i]=='b')m[h][w++]='b';
		else{
			for(int j=0;j<s[i]-'0';j++)m[h][w++]='.';
		}
	}
	h++;
}

string crypt(){
	string s="";
	int l=0;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(m[i][j]=='b'){
				if(l!=0)s+=(char)('0'+l);
				l=0;
				s+='b';
			}
			else l++;
		}
		if(l!=0)s+=(char)('0'+l);
		l=0;
		s+='/';
	}
	s.erase(--s.end());
	return s;
}
int main(void){
	string s;
	int a,b,c,d;
	while(cin>>s,s!="#"){
		cin>>a>>b>>c>>d;
		a--;b--;c--;d--;
		decrypt(s);
		m[a][b]='.';
		m[c][d]='b';
		cout<<crypt()<<endl;
	}
}