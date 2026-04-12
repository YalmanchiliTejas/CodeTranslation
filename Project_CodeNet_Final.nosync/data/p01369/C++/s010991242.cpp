#define	_USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <cfloat>
#include <map>
#include <queue>
#include <stack>
#include <list>
using namespace std;
int main(){

	map<char,int> l;
	
	l['q']=1;
	l['w']=1;
	l['e']=1;
	l['r']=1;
	l['t']=1;
	l['a']=1;
	l['s']=1;
	l['d']=1;
	l['f']=1;
	l['g']=1;
	l['z']=1;
	l['x']=1;
	l['c']=1;
	l['v']=1;
	l['b']=1;
	l['y']=2;
	l['u']=2;
	l['i']=2;
	l['o']=2;
	l['p']=2;
	l['h']=2;
	l['j']=2;
	l['k']=2;
	l['l']=2;
	l['n']=2;
	l['m']=2;
	
	string s;
	int k;
	
	while(cin>>s,s!="#"){
		k=l[s[0]];
		int c=0;
		for(int i=1;i<s.size();i++){
		//	cout<<c<<k<<endl;
		//	cout<<s[i]<<l[s[i]]<<endl;
			if(k==1){
				if(l[s[i]]!=1){
					k=l[s[i]];
					c++;
				}
			}
			else{
				if(l[s[i]]!=2){
					k=l[s[i]];
					c++;
				}
			}
		}
		cout<<c<<endl;
	}
}