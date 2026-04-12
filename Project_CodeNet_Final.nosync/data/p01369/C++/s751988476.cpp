#include <bits/stdc++.h>
using namespace std;
int main(void){
    map<char, int> mp;
	string str;
    mp['q']=11;mp['a']=12;mp['z']=13;
	mp['w']=21;mp['s']=22;mp['x']=23;
	mp['e']=31;mp['d']=32;mp['c']=33;
	mp['r']=41;mp['f']=42;mp['v']=43;
	mp['t']=51;mp['g']=52;mp['b']=53;
	mp['y']=61;mp['h']=62;mp['n']=63;
	mp['u']=71;mp['j']=72;mp['m']=73;
	mp['i']=81;mp['k']=82;
	mp['o']=91;mp['l']=92;
	mp['p']=101;
	while(1){
	cin >> str;
	//auto itr=str.begin();
	if(str[0]=='#')break;
	int pos=0;
	    int hand=0;
	    int count=0;
	for(int i=0;i<str.size();i++){
		char x=str[i];
		if(!pos){
			pos=mp[x];
			hand=(pos/60);
		}
		else{
			if((mp[x]/60)!=hand){
				count++;
				hand=1-hand;
			}
			pos=mp[x];
		}
	}
	cout <<count<<endl;
	
    }
}