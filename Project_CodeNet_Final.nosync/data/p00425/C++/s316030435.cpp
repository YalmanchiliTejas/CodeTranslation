#include<iostream>
#include<string>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(n) rep(i,n)

#define T 1
#define S 2
#define E 3
#define W 4
#define N 5
#define B 6

int sai[10] ={0,T,S,E,W,N,B};

void turn(string s)
{
	int t=0;
	if(s=="North")
	{
		t = sai[N];
		sai[N] = sai[T];
		sai[T] = sai[S];
		sai[S] = sai[B];
		sai[B] = t;
	}
	if(s=="South")
	{
		t = sai[S];
		sai[S] = sai[T];
		sai[T] = sai[N];
		sai[N] = sai[B];
		sai[B] = t;
	}
	if(s=="West")
	{
		t = sai[W];
		sai[W] = sai[T];
		sai[T] = sai[E];
		sai[E] = sai[B];
		sai[B] = t;
	}
	if(s=="East")
	{
		t = sai[E];
		sai[E] = sai[T];
		sai[T] = sai[W];
		sai[W] = sai[B];
		sai[B] = t;
	}
	if(s=="Right")
	{
		t = sai[E];
		sai[E] = sai[N];
		sai[N] = sai[W];
		sai[W] = sai[S];
		sai[S] = t;
	}
	if(s=="Left")
	{
		t = sai[W];
		sai[W] = sai[N];
		sai[N] = sai[E];
		sai[E] = sai[S];
		sai[S] = t;
	}
	//debug
	//cout << "T,N,E:" << sai[T] <<"," << sai[N] <<"<" << sai[E]  << endl;

}


int main()
{
	int n;
	while(cin >> n && n)
	{
		REP(8) sai[i] = i;
		string ss;
		int ans = 1;
		REP(n)
		{
			cin >> ss;
			turn(ss);
			ans += sai[T];
		}
		cout << ans << endl;
	}
	return 0;
}