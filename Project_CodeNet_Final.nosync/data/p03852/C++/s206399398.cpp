//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

#define SORT(c) sort((c).begin(),(c).end())
#define ANS(ans) cout<<(ans)<<endl;
typedef vector<int> VI;


//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  for (int i = 0; i < (n); ++i)


int main() {
	char c;
  cin>>c;
  if(c=='a' || c=='i' || c=='u'|| c=='e'|| c=='o'){
    cout<<"vowel"<<endl;
  }else{
    cout<<"consonant"<<endl;
  }

	return 0;
}

