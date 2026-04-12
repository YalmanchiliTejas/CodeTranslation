#include<iostream>
#include<set>
#include<string>

using namespace std;

#define NMAX 20

int main(){

	set<char> l;
	string in;

	l.insert('q');
	l.insert('w');
	l.insert('e');
	l.insert('r');
	l.insert('t');
	l.insert('a');
	l.insert('s');
	l.insert('d');
	l.insert('f');
	l.insert('g');
	l.insert('z');
	l.insert('x');
	l.insert('c');
	l.insert('v');
	l.insert('b');

	while(1){
		cin>>in;
		if(in=="#") break;
		int aa;
		int ans=0;
		if(l.find(in[0])!=l.end()) aa=1;
		else aa=-1;
		for(int i=1;i<in.size();i++){
			if(l.find(in[i])!=l.end()){
				if(aa==-1) ans++;
				aa=1;
			}
			else{
				if(aa==1) ans++;
				aa=-1;
			}
		}
		cout<<ans<<endl;
	}

}