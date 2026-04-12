#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
	int h, w;
	cin>>h>>w;
	string a[8];
	for(int i=0; i<h; i++) cin>>a[i];
	int ct=0;
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(a[i][j]=='#') ct++;
		}
	}
	if(ct==h+w-1) cout<<"Possible"<<endl;
	else cout<<"Impossible"<<endl;
	return 0;
}