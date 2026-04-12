#include <vector>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <deque>
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

#define REP(i,n)for (int i=0;i<(n);i++)
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define ll long long
using namespace std;
string s="aeiou";

int main(){
	char c;
	cin>>c;
	bool f=false;
	REP(i,s.size()){
		if(c==s[i])f=true;
	}
	if(f){
		cout<<"vowel"<<endl;
	}else{
		cout<<"consonant"<<endl;
	}
}

