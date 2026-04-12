#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define PB push_back
#define F first
#define S second
typedef pair<char,string> P;
map<char,string> ma1;
vector<P> v;
vector<vector<P> > vv(10);
int main(){
	string aaa="ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";
	rep(i,aaa.size()){
		string t="00000";
		rep(j,5){
			t[4-j]=(i>>j)&1;
			t[4-j]+='0';
		}
		ma1[aaa[i]]=t;
		// cout<<aaa[i]<<" "<<ma1[aaa[i]]<<endl;
	}
	// char tmp=' ';
	string tmp="'";
	v.PB(P(' ',"101"));
	v.PB(P(tmp[0],"000000"));
	v.PB(P(',',"000011"));
	v.PB(P('-',"10010001"));
	v.PB(P('.',"010001"));
	v.PB(P('?',"000001"));
	v.PB(P('A',"100101"));
	v.PB(P('B',"10011010"));
	v.PB(P('C',"0101"));
	v.PB(P('D',"0001"));
	v.PB(P('E',"110"));
	v.PB(P('F',"01001"));
	v.PB(P('G',"10011011"));
	v.PB(P('H',"010000"));
	v.PB(P('I',"0111"));
	v.PB(P('J',"10011000"));
	v.PB(P('K',"0110"));
	v.PB(P('L',"00100"));
	v.PB(P('M',"10011001"));
	v.PB(P('N',"10011110"));
	v.PB(P('O',"00101"));
	v.PB(P('P',"111"));
	v.PB(P('Q',"10011111"));
	v.PB(P('R',"1000"));
	v.PB(P('S',"00110"));
	v.PB(P('T',"00111"));
	v.PB(P('U',"10011100"));
	v.PB(P('V',"10011101"));
	v.PB(P('W',"000010"));
	v.PB(P('X',"10010010"));
	v.PB(P('Y',"10010011"));
	v.PB(P('Z',"10010000"));
	rep(i,v.size()){
		vv[v[i].S.size()].PB(v[i]);
	}

	string s;
	while(getline(cin,s)){
		string t;
		rep(i,s.size()){
			t=t+ma1[s[i]];
		}
		// cout<<t<<endl;
		int pos=0;
		string ans;
		
		rep(i,t.size()){
			rep(j,vv[i-pos+1].size()){
				if(t.substr(pos,i-pos+1)==vv[i-pos+1][j].S){
					string ts="1";
					ts[0]=vv[i-pos+1][j].F;
					ans=ans+ts;
					pos=i+1;
					break;
				}
			}
		}
		
		cout<<ans<<endl;
	}

}


/*
101 ' '
110 E
111 P

0101 C
0001 D
0111 I
0110 K
1000 R

01001 F
00101 O
00100 L
00110 S
00111 T

000000 '
000011 ,
010001 .
000001 ?
100101 A
010000 H
000010 W















*/