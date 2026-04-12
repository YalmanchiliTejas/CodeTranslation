#include <iostream>
using namespace std;
typedef long long LL;
int main(int argc, char* argv[])
{
	LL A,B,C,X,Y;
	cin>>A>>B>>C>>X>>Y;

	LL minXY=min(X,Y);
	LL c=2*C*max(X,Y);
	cout<<min(min(2*C*minXY+(X-minXY)*A+(Y-minXY)*B,A*X+B*Y),c)<<endl;
	return 0;
}