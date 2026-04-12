#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
#include <functional>

using namespace std;
typedef long long ll;
typedef pair<int,int>P;


int A,B,C,X,Y;

int c1()
{
	return A*X+B*Y;
}

int c2()
{
	return min(X,Y)*2*C+(max(X-X,X-Y)*A)+(max(Y-X,Y-Y)*B);
}

int c3()
{
	return max(X,Y)*2*C;
}

int main()
{
	cin>>A>>B>>C>>X>>Y;
	vector<int>t={c1(),c2(),c3()};
	cout<<min(t[0],min(t[1],t[2]))<<endl;

}