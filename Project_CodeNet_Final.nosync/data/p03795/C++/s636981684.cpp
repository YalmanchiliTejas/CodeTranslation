#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	int N;
	cin>>N;
	int y=N/15*200;
	int x=800*N;
	cout<<x-y<<endl;
	return 0;
}
