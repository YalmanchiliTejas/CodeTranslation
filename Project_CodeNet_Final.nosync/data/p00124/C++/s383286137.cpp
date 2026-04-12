#include<iostream>
#include<cstdio>
#include <cstring>
#include<map>
#include<string>
#include<stack>
#include <algorithm>
#include <strstream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

int main(){
	int n;
	bool next = false;
	int w,l,d=0;
	while(cin>>n && n)
	{
		 if ( next )
        {
            cout << endl;
        }
        next = true;
		multimap< int,string,greater<int> >m;
		for(int i=0; i<n; i++)
		{
			string t;
			cin>>t>>w>>l>>d;
			m.insert( make_pair( w*3+d , t ) );
		}
		for(multimap< int,string,greater<int> >::iterator it=m.begin(); it != m.end(); it++)
			cout<< (*it).second << ',' << (*it).first << endl;
	}
	return 0;
}