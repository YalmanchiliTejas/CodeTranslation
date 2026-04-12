#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <cctype>
#define fore(i,x,y) for(long long i=x;i<y;i++)
typedef long long ll;
using namespace std;
int main()
{
	int r,g,b,x;
	cin >> r >> g >> b;
	x=10*g+b;
	if(x%4==0){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}

}