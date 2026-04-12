#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<map>
#include<cmath>
#include<queue>	

using namespace std;

namespace MyLib {
#define ALL(a) a.begin(),a.end()
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define debug(x) if(1)cout<<#x<<":"<<x<<endl;
#define DEBUG(x) if(1)cout<<#x<<":"<<x<<endl;
#define ll long long
}

using namespace MyLib;


int main() {
	string s;
	while (cin >> s, s[0] != '#') {
		int lef;
		if ('a' <= s[0] && s[0] <= 'g' || 'q' <= s[0] && s[0] <= 't' || s[0] == 'v' || s[0] == 'w' || s[0] == 'x' || s[0] == 'z')
			lef = 1;
		else
			lef = 0;
		int count = 0;
		for (int i = 1; i < s.size(); i++)
			if ('a' <= s[i] && s[i] <= 'g' || 'q' <= s[i] && s[i] <= 't' || s[i] == 'v' || s[i] == 'w' || s[i] == 'x' || s[i] == 'z')
				if (!lef) {
					count++;
					lef = 1;
				}
				else
					lef = 1;
			else
				if (lef) {
					count++;
					lef = 0;

				}
				else
					lef = 0;
		cout << count << endl;




	}

	return 0;

}