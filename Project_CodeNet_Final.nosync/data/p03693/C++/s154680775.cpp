#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <algorithm> 
#include <ctime>

int N,X;

using namespace std;


int main()
{
	cin>>N;
	cin>>X;
	N=10*N+X;
	cin>>X;
	N=10*N+X;
	if(N%4==0)
		cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}