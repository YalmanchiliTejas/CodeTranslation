#include <string.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <istream>
#define INF 2147483647
#define LLINF 9223372036854775807
typedef long long ll;
using namespace std;
int dpl[110][5];
int dpe[110][5];
int main(){
	string s;
	int k;
	cin>>s>>k;
	for(int i=0;i<s.size();i++){
		int c=(int)(s[i]-'0');
		if(!i){
			for(int j=1;j<c;j++)dpl[1][1]++;
			dpe[1][1]++;
		}
		else{
			for(int j=1;j<10;j++)dpl[i+1][1]++;
			for(int j=0;j<=k;j++){
				dpe[i+1][j+(c>0)]+=dpe[i][j];
				for(int l=0;l<c;l++){
					dpl[i+1][j+(l>0)]+=dpe[i][j];
				}
				for(int l=0;l<10;l++){
					dpl[i+1][j+(l>0)]+=dpl[i][j];
				}
			}
		}
	}
	cout<<dpl[s.size()][k]+dpe[s.size()][k]<<endl;
	return 0;
}