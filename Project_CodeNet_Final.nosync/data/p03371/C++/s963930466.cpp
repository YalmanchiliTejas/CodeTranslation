#include<iostream>

using namespace std;

int main()
{
	int a,b,c,x,y;

	cin >> a >> b >> c >> x >> y;

	int i,min;
	if(a+b > c*2) min=c*2;
	else min=a+b;


	int co,am,ad;
	if(x > y){
		co = y*min;
		am = x-y;
		if(a+b > c*2){
			if(min < a)
				ad = co + (min*am);
			else
				ad = co + a*am;
		}
		else
			ad = co + a*am;	
	}
	else if(x < y){
		co = x*min;
		am = y-x;
		if(a+b > c*2){
			if(min < b)
				ad = co + (min*am);
			else
				ad = co + b*am;
		}
		else
			ad = co + b*am;
	}
	else{
		cout << min*x << endl;
		return 0;
	}

	cout << ad << endl;

	return 0;
}






