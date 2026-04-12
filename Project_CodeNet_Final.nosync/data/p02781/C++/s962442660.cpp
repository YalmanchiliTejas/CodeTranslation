#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <map>
typedef long long ll;
#include <cmath>


ll sub(string s, int k)
{
	//cerr<<"["<<s<<"]"<<k<<endl;
	if (k==0) return 1;
	if (s=="") return 0;
	string _9=string(s.length()-1,'9');
	string s1=s.substr(1);
	
	if (s[0]=='0') return sub(s1,k);
	ll ret=0;
	if (s[0]>'1') ret+=(s[0]-'0'-1)*sub(_9,k-1);
	ret+=sub(_9,k);
	ret+=sub(s1,k-1);
	return ret;
}

int main(int argc, char *argv[])
{
	string n;
	int k;
	ll ret=0;

	cin >> n>>k;
	
	ret=sub(n,k);

	cout<<ret<<endl;
	return 0;
}
