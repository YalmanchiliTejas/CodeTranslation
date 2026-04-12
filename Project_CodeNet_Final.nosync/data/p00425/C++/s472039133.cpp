
#include <iostream>
#include <string>
using namespace std;

class Dice
{
public:
	enum Pos{TOP, FRONT, RIGHT};

private:
	typedef Pos PosInfo[3];
	unsigned mFront, mBack, mLeft, mTop, mRight, mBottom;

	void RotationFromL(unsigned& a, unsigned& b, unsigned& c, unsigned& d)
	{ d=c; c=b; b=a; a=7-c; }

public:
	Dice(Pos _1=TOP, Pos _2=FRONT, Pos _3=RIGHT)
	{
		if(_1==_2 || _2==_3)
		{ _1=TOP; _2=FRONT; _3=RIGHT; }
	
		PosInfo posinfo={_1,_2,_3};
		for(int i=0; i<3; i++)
			switch(posinfo[i])
			{
			case TOP   : mBottom = 7-(mTop=i+1);    break;
			case FRONT : mBack   = 7-(mFront=i+1);  break;
			case RIGHT : mLeft   = 7-(mRight=i+1);  break;
			}
	}
	unsigned Front()const{ return mFront; }
	unsigned Back()const{ return mBack; }
	unsigned L()const{ return mLeft; }
	unsigned R()const{ return mRight; }
	unsigned T()const{ return mTop; }
	unsigned B()const{ return mBottom; }

	void ToNorth(){ RotationFromL(mTop, mBack , mBottom, mFront); }
	void ToSouth(){ RotationFromL(mTop, mFront, mBottom, mBack ); }
	void ToEast (){ RotationFromL(mTop, mRight, mBottom, mLeft ); }
	void ToWest (){ RotationFromL(mTop, mLeft, mBottom, mRight ); }
	void Turn_R (){ RotationFromL(mRight, mFront, mLeft, mBack); }
	void Turn_L (){ RotationFromL(mRight, mBack, mLeft, mFront); }
};


int main(void)
{
	string cmd;
	const string
		N("North"), E("East"), W("West"), S("South"),
		L("Left"), R("Right");

	while(1)
	{
		Dice d;
		int n, sum=1;
		cin >> n;
		if(n==0)break;
		
		for(int i=0; i<n; i++)
		{
			cin >> cmd;
			if(cmd == N)d.ToNorth();
			if(cmd == E)d.ToEast();
			if(cmd == W)d.ToWest();
			if(cmd == S)d.ToSouth();
			if(cmd == L)d.Turn_L();
			if(cmd == R)d.Turn_R();
			sum += d.T();
		}
		cout << sum << endl;
	}
	return 0;
}