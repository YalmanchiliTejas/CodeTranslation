#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>
#include <vector>
#include <map>
#define T 0
#define R 1
#define F 2
#define L 3
#define B 4
#define Bt 5
using namespace std;

vector<int> dice;

void No()
{
  int tmp = dice[T];
  dice[T] = dice[F];
  dice[F] = dice[Bt];
  dice[Bt] = dice[B];
  dice[B] = tmp;
}

void Ea()
{
 int tmp = dice[T];
  dice[T] = dice[L];
  dice[L] = dice[Bt];
  dice[Bt] = dice[R];
  dice[R] = tmp;
}

void We()
{
  int tmp = dice[T];
  dice[T] = dice[R];
  dice[R] = dice[Bt];
  dice[Bt] = dice[L];
  dice[L] = tmp;
}

void Sou()
{
 int tmp = dice[T];
  dice[T] = dice[B];
  dice[B] = dice[Bt];
  dice[Bt] = dice[F];
  dice[F] = tmp;
}

void Rig()
{
  int tmp = dice[R];
  dice[R] = dice[B];
  dice[B] = dice[L];
  dice[L] = dice[F];
  dice[F] = tmp;
}

void Lef()
{
  int tmp = dice[R];
  dice[R] = dice[F];
  dice[F] = dice[L];
  dice[L] = dice[B];
  dice[B] = tmp;
}

int main()
{
  int n;
  dice.resize(6);
  

  while(cin >> n,n)
    {
      int sum = 1;
      dice[0] = 1,dice[1] = 3,dice[2] = 2,dice[3] =4,dice[4] = 5,dice[5] = 6;
      string ope;
      for(int i=0;i<n;i++)
	{
	  cin >> ope;
	  if(ope == "North")
	    No();
	  else if(ope == "East")
	    Ea();
	  else if(ope == "West")
	    We();
	  else if(ope == "South")
	    Sou();
	  else if(ope == "Right")
	    Rig();
	  else if(ope == "Left")
	    Lef();
	
	  sum += dice[T];
	}
      cout << sum << endl;
    }
  return 0;
}