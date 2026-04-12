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
	char a;
	cin >> a;
	if(a=='a'||a=='i'||a=='u'||a=='e'||a=='o'){
		cout << "vowel" << endl;
	}
	else{
		cout << "consonant" << endl;
	}
}