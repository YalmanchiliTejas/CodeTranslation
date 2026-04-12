#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class page
{
	public:
	
		int nlink;
		string name;
		vector<string> tostr;
		vector<int> x1,y1,x2,y2,to;
};

int main()
{
	int n,m,W,H;
	int xx1,yy1,xx2,yy2;
	string tname; int ln;

	while(cin >> n, n)
	{
		map<string,int> mp;
		page pg[128];
		vector<int> hist;


		cin >> W >> H;
		for(int i=0; i<n; i++)
		{
			cin >> tname >> ln;
			mp[tname] = i;
			pg[i].name  = tname;
			pg[i].nlink = ln;
			while(ln--)
			{
				cin >> xx1 >> yy1 >> xx2 >> yy2 >> tname;
				pg[i].x1.push_back(xx1);
				pg[i].y1.push_back(yy1);
				pg[i].x2.push_back(xx2);
				pg[i].y2.push_back(yy2);
				pg[i].tostr.push_back(tname);
			}
		}

		for(int i=0; i<n; i++)
		for(int j=0; j<pg[i].tostr.size(); j++)
		{
			pg[i].to.push_back(mp[pg[i].tostr[j]]);
		}


		cin >> m; int idx=0;
		hist.push_back(0);
		while(m--)
		{
			cin >> tname;
			if(tname=="click")
			{
				cin >> xx1 >> yy1;
				
				for(int i=0; i<pg[hist[idx]].to.size(); i++)
				{
					if(pg[hist[idx]].x1[i]<=xx1 && xx1<=pg[hist[idx]].x2[i]
					&& pg[hist[idx]].y1[i]<=yy1 && yy1<=pg[hist[idx]].y2[i])
					{
						hist.resize(idx+1);
						hist.push_back(pg[hist[idx]].to[i]);
						idx++;
						break;
					}
				}
			}
			else if(tname=="show")
			{
				cout << pg[hist[idx]].name << endl;
			}
			else if(tname=="back")
			{
				if(idx>0) idx--;
			}
			else if(tname=="forward")
			{
				if(idx<hist.size()-1) idx++;
			}
		}
	}
}