#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int x = 0;
	int y = 0;
	int k = 0;
	cin>>x>>y>>k;
	x = x - k;
	int total = x/(y+k);
	cout<<total;
	cout<<endl;
}