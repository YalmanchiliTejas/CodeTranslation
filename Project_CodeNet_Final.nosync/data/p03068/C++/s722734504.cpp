#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <bitset>
#include <cstdlib>
#include <cmath>
#define INF 1000000000
#define MOD 1000000007
#define ll long long int
using namespace std;

int main(){
	int N,K;
	string s;
	cin>>N;
	cin>>s;
	cin>>K;
	char a = s[K-1];
	for(int i=0;i<N;i++){
		if(s[i] != a) s[i] = '*';
	}
cout<<s<<endl;
	return 0;
}