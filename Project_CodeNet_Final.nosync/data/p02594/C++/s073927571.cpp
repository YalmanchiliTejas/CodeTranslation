#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() {
	int x;
	cin>>x;
	if(x>=-40&&x<=40)
	{
		if (x>=30)
		{
			cout<<"Yes";
		}
		else
		{
			cout<<"No";
		}
	}
	return 0;
}