#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <cstdio>
#include <climits>
#include <cmath>
#include <array>
#include <functional>
#include <sstream>
#include <list>
#include <iomanip>
#include <set>
const int MOD=1000000007;
const int INF=1000000000;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const double eps=1e-9;
const int inf=1e9;
typedef pair<int,int> P;
struct Point
{
  double x,y;
  Point(){x=0;y=0;}
  Point(double d_x,double d_y){x=d_x,y=d_y;}
  double operator*(Point obj){return obj.x*x+obj.y*y;}
  double operator%(Point obj){return obj.y*x-obj.x*y;}
  Point operator*(double b){Point tmp;tmp.x=x*b;tmp.y=y*b;return tmp;}
  Point operator/(double b){Point tmp;tmp.x=x/b;tmp.y=y/b;return tmp;}
  Point operator+(Point obj){Point tmp;tmp.x=x+obj.x;tmp.y=y+obj.y;return tmp;}
  Point operator-(){Point tmp;tmp.x=-x;tmp.y=-y;return tmp;}
  Point operator-(Point obj){Point tmp;tmp.x=x-obj.x;tmp.y=y-obj.y;return tmp;}
  Point operator-=(Point obj){x-=obj.x;y-=obj.y;return *this;}
  Point operator+=(Point obj){x+=obj.x;y+=obj.y;return *this;}
  Point operator/=(double b){x=x/b;y=y/b;return *this;}
  Point operator*=(double b){x=x*b;y=y*b;return *this;}
  double size(){return hypot(x,y);}
  Point unit(){return Point(x/size(),y/size());}
  Point normal(){return Point(y,-x);}
  double atan(){return atan2(y,x);}
};

bool operator<(Point a,Point b){return a.x!=b.x?a.x<b.x:a.y<b.y;}
bool operator>(Point a,Point b){return b<a;}
bool operator<=(Point a,Point b){return !(b<a);}
bool operator>=(Point a,Point b){return !(a<b);}
bool operator==(Point a,Point b){return (a-b).size()<eps;}
bool operator!=(Point a,Point b){return !(a==b);}

bool equal(double a,double b){return abs(a-b)<eps;}
double cross(Point a,Point b){return a%b;}
double dot(Point a,Point b){return a*b;}

int ccw(Point a,Point b,Point c)
{
  b=b-a;
  c=c-a;
  if(b%c>0) return +1;
  else if(b%c<0)return -1;
  else if(b*c<0) return +2;
  else if(b.size()<c.size()) return -2;
  else return 0;
}

int convert(char num)
{
  if(num=='T')
    {
      return 10;
    }
  else if(num=='J')
    {
      return 11;
    }
  else if(num=='Q')
    {
      return 12;
    }
  else if(num=='K')
    {
      return 13;
    }
  else if(num=='A')
    {
      return 14;
    }
  else
    {
      return (int)(num-'0');
    }
}

int main(int argc,char const* argv[])
{
  while(1)
    {
      char trump;
      cin >> trump;
      if(trump=='#') break;
      vector<string> cards[4];
      for(int i=0;i<4;i++)
	{
	  for(int j=0;j<13;j++)
	    {
	      string tmp;
	      cin >> tmp;
	      cards[i].push_back(tmp);
	    }
	}
      int ew=0,ns=0,tmpwinner=0;
      for(int i=0;i<13;i++)
	{
	  char lead;
	  int mx=0;
	  lead=cards[tmpwinner][i][1];
	  if(lead==trump)
	    {
	      mx=convert(cards[tmpwinner][i][0])+15;
	    }
	  else
	    {
	      mx=convert(cards[tmpwinner][i][0]);
	    }   
	  for(int j=0;j<4;j++)
	    {
	      if(cards[j][i][1]==lead && cards[j][i][1]!=trump)
		{
		  if(convert(cards[j][i][0])>mx)
		    {
		      mx=convert(cards[j][i][0]);
		      tmpwinner=j;
		    }
		}
	      else if(cards[j][i][1]==trump)
		{
		  if(convert(cards[j][i][0])+15>mx)
		    {
		      mx=convert(cards[j][i][0])+15;
		      tmpwinner=j;
		    }
		}		
	    }
	  if(tmpwinner%2==0) ns++;
	  else ew++;
	}
      if(ew>ns)
	{
	  cout << "EW" << ' ' << ew-6 << endl;
	}
      else
	{
	  cout << "NS" << ' ' << ns-6 << endl;
	}
    }
  return 0;
}
	  

