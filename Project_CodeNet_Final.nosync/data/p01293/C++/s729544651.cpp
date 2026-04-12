#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define inf (1<<29)

using namespace std;

char Trump;
string cards[4][13];
bool awin(char a,char b)
{
  int pa = (isdigit(a)?a-'0':(a=='T'?10:(a=='J'?11:(a=='Q'?12:(a=='K'?13:(a=='A'?14:inf))))));
  int pb = (isdigit(b)?b-'0':(b=='T'?10:(b=='J'?11:(b=='Q'?12:(b=='K'?13:(b=='A'?14:inf))))));
  return pa > pb;
}

void compute()
{
  int points[2];
  points[0] = points[1] = 0;
  int winner = 0;
  rep(i,13)
    {
      bool trump = (cards[0][i][1] == Trump);
      char suit = cards[winner][i][1];
      int mex = 0;
      REP(j,1,4)
	{
	  if(trump)
	    {
	      if(Trump != cards[j][i][1])continue;
	      if(awin(cards[j][i][0],cards[mex][i][0]))mex = j;
	    }
	  else
	    {
	      if(Trump == cards[j][i][1])
		{
		  trump = true;
		  mex = j;
		  continue;
		}
	      if(cards[mex][i][1] != suit)mex = j;
	      if(suit == cards[j][i][1])
		{
		  if(awin(cards[j][i][0],cards[mex][i][0]))mex = j;
		}
	    }
	}

      points[(mex==1||mex==3)?0:1]++;
      winner = mex;
      //cout << "winner : " << mex << " suit : " << suit << endl;
    }
  //cout << "posint " << points[0] << " " << points[1] << endl;
  cout << ( points[0] > points[1] ? "EW" : "NS") << " " << (points[0] < points[1]?points[1]:points[0])-6 << endl;
}

int main()
{
  while(cin >> Trump,Trump!='#')
    {
      rep(i,4)rep(j,13)cin >> cards[i][j];
      compute();
    }
  return 0;
}