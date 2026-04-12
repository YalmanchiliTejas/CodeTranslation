#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

struct P { int x,y; P(int x_,int y_):x(x_),y(y_){} P(){} };

int main()
{
	while ( true )
	{
		int w,h; cin>>w>>h;
		if ( w == 0 )
			break;
		vector<vector<P> > S(1);
		P g;

		for ( int y=0; y<h; y++ )
		for ( int x=0; x<w; x++ )
		{
			string s; cin>>s;
			if ( s=="S" )
				S[0].push_back(P(x,y));
			else if ( s=="G" )
				g = P(x,y);
			else if ( s=="." )
				;
			else
			{
				int n = atoi(s.c_str());
				if ( S.size() < n+1 )
					S.resize(n+1);
				S[n].push_back(P(x,y));
			}
		}

		S.push_back(vector<P>(1,g));

		int n = (int)S.size();

		//for ( int i=0; i<n; i++ )
		//{
		//	for ( int j=0; j<(int)S[i].size(); j++ )
		//		cout << "{"<<S[i][j].x<<","<<S[i][j].y<<"},";
		//	cout << endl;
		//}

		vector<vector<int> > T(n);
		for ( int i=0; i<n; i++ )
			T[i] = vector<int>(S[i].size(),99999999);
		T[0][0] = 0;
		for ( int i=1; i<n; i++ )
		{
			for ( int j=0; j<S[i].size(); j++ )
			for ( int k=0; k<S[i-1].size(); k++ )
				T[i][j] = min( T[i][j], T[i-1][k]+abs(S[i][j].x-S[i-1][k].x)+abs(S[i][j].y-S[i-1][k].y) );
		}

		cout << T.back()[0] << endl;
		
	}
	return 0;
}