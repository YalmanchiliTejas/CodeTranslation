#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<random>
#include<math.h>
#include<limits.h>
#include<iterator>
#include<queue>
#include<functional>
#define rep(i,a) for(int i=0;i<a;i++)
#define nrep(i,a,b) for(int i=a;i<b;i++)
#define mrep(i,a) for(int i=a;i>=0;i--)
#define ll long long
#define vl vector<ll> 
#define vvl vector<vector<ll> > 
#define vb vector<bool> 
#define vvb vector<vector<bool> > 
#define INF 11234567890123456789
using namespace std;


int main(){
	string s; cin >> s;
	rep(i, s.size() - 1){
		if (s[i] == 'A'&&s[i + 1] == 'C'){
			cout << "Yes" << std::endl;
			return 0;
		}
	}cout << "No" << endl;
	return 0;
}