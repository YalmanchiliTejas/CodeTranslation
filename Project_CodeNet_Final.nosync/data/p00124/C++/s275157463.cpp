#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
int main(void){
	bool b=false;
	while(1){
		int a,n;
		string s;
		multimap<int, string, greater<int> > P;
		int w,d,l;
		cin >> n;
		if(n==0)break;
		if(b==true)cout << endl;
		b=true;
		for(a=0;a<n;a++){
			 cin >> s >> w >> l >> d; 
			P.insert( pair<int, string>(w*3+d,s));
		}
		multimap<int, string, greater<int> >::iterator it = P.begin();
		while( it != P.end() )	{
			cout << (*it).second << "," << (*it).first << endl;
			++it;
		}
	}
	return 0;
}