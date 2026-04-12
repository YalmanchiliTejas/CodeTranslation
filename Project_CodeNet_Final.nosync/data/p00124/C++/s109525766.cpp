#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct team{
  int point;
  int mun;
  string name;
};

class LessAn {
public:
    bool operator()(const team& a, const team& b)
    {
      if(a.point==b.point)
        return a.mun < b.mun;
      return a.point > b.point;
    }
};




int main()
{
  bool x=false;
  int n;
  for(;cin>>n,n;)
    {
      if(x)
	cout<<endl;
      else
	x=true;
      vector<team> t;      
      for(int i=1;n--;i++)
      {
	string tt;
	int x,y,z;
	team a;
	cin>>tt>>x>>y>>z;
	a.point=x*3+z;
	a.name=tt;
	a.mun=i;
	t.push_back(a);
      }
      sort(t.begin(), t.end(),LessAn());
	for(int i=0;i<t.size();i++)
	  {
	    cout<<t[i].name<<","<<t[i].point<<endl;
	  }
    }
}