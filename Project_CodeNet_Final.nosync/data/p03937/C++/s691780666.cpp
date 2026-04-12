#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iterator>
#include <set>
#include <functional>

using namespace std;

#define DT int
#define forn(i,n)for(i=0;i<n;i++)
#define forc(i,c,n)for(i=c;i<=n;i++)
typedef vector<DT> vc;
typedef list<DT> li;

int main() {
	//ifstream fin("Text.txt");
	int i, j;
	DT a,b,c,n,m=0,h,w;
	char ch;
	cin>>h>>w;
	forn(i,h){
		forn(j,w){
			cin>>ch;
			if(ch=='#')
				m++;
		}
	}
	if(m==h+w-1){
		cout<<"Possible"<<endl;
	}
	else{
		cout<<"Impossible"<<endl;
	}
	return 0;
}