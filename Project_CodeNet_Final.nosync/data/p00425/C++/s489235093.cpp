#include<iostream>
#include<string>

using namespace std;

template <class T> void swapQ(T *a, T *b, T *c, T *d)
{
	T buf;

	buf = *a;
	*a = *b;
	*b = *c;
	*c = *d;
	*d = buf;
}

class CDice
{
	int N, E, W, S, U, B, P;
public:
	CDice():U(1),S(2),E(3),W(4),N(5),B(6),P(1){}

	void  Rotate(string);
	int getPoint();
};
void CDice::Rotate(string s)
{
	//ñ]
	if(s == "North") swapQ(&U, &S, &B, &N);
	if(s == "East")  swapQ(&U, &W, &B, &E);
	if(s == "West")	 swapQ(&U, &E, &B, &W);
	if(s == "South") swapQ(&U, &N, &B, &S);
	if(s == "Right") swapQ(&S, &E, &N, &W);
	if(s == "Left")  swapQ(&S, &W, &N, &E);
	
	//Á_
	P += U; 
}
int CDice::getPoint()
{
	return P;
}

int main()
{
	int n;
	string str;
	while(1){
		cin>>n;
		if(n == 0) return 0;

		CDice dice;
		for(int i = 0; i < n; i++){
			cin>>str;
			dice.Rotate(str);
		}
		cout<<dice.getPoint()<<endl;
	}
}