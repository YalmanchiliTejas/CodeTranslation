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
#include <iomanip>
//cout << fixed << setprecision(20) << *** << endl;
#define rep(i,N) for(int i=0;i<(int)N;++i)
typedef long long ll;
using namespace std;
int main()
{
	string s,ANS="No";
	cin>>s;
	rep(i,s.size()-1){
		if(s[i]=='A'&&s[i+1]=='C')ANS="Yes";
	}
	cout<<ANS<<endl;
}