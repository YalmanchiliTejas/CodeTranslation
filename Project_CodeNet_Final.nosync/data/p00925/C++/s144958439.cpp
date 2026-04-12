#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define FORD(x,y,z) for(int x=y;x>=z;x--)
#define MSET(x,y) memset(x,y,sizeof(x))
#define FOR(x,y) for(__typeof(y.begin()) x=y.begin();x!=y.end();x++)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define M 20
#define INF 1000000000
void RI(){}
template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
using namespace std;
typedef long long LL;
int n;
vector<string> in;
void read()
{
	string buf;
	cin >> buf;

	string cur = "";
	REP(i,0,(int)buf.length()-1)
	{
		if(buf[i]>='0' && buf[i]<='9') cur += buf[i];
		else
		{
			if(cur.length()) in.PB(cur);
			cur = buf[i];
			in.PB( cur );
			cur = "";
		}
	}
	if(cur.length()) in.PB(cur);
}
int main()
{
	bool a1=false, a2=false;
	read();
	RI(n);

	//1
	int op=0, x;
	LL cur=0, tmp;
	FOR(i,in)
	{
		if((*i)[0]>='0' && (*i)[0]<='9')
		{
			tmp = atoi(i->c_str());
			if(op==0) cur = cur + tmp;
			else      cur = cur * tmp;
			if(cur >= INF) break;
		}
		else
		{
			if(*i == "+") op=0;
			else op=1;
		}
	}
	a1 = (n==cur);


	//2
	vector<LL> vec;
	op = 0;
	FOR(i,in)
	{
		if(*i=="+") op=0;
		else if(*i=="*") op=1;
		else
		{
			x = atoi(i->c_str());
			if(op==1)
			{
				tmp = vec.back();
				vec.pop_back();
				tmp *= x;
				if(tmp >= INF) tmp = INF;
				vec.PB(tmp);
			}
			else
			{
				vec.PB(x);
			}
		}
	}

	cur = 0;
	cur = accumulate(vec.begin(), vec.end(), cur);
	a2 = (n==cur);

	if(a1 && a2) puts("U");
	if(!a1 && !a2) puts("I");
	if(a1 && !a2) puts("L");
	if(!a1 && a2) puts("M");
	return 0;
}