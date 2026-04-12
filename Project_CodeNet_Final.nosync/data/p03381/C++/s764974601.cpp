#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<vector>
#include<deque>
#include<queue>

using std::cout;
using std::cin;
using std::setw;
using std::setfill;
using std::string;
using std::pair;
using std::make_pair;
using std::vector;
using std::queue;
using std::deque;
using std::priority_queue;
using std::next_permutation;
//using std::iota;
using std::sort;
using std::greater;
using std::max;
using std::min;

using lli = long long int;
using ulli = unsigned long long int;

#define INF 999999999;

//#define EVEL 1

#ifndef EVEL00
#define dbug(X) std::cout << #X << ":" <<X<<" " ;
#define dbugf(s) std::cout << s << " ";
#define dbugln std::cout<<"\n";
#else
#define dbug(X) {}
#define dbugf(s) {}
#define dbugln {}
#endif

ulli X[200010];
vector<ulli> Xs;
ulli N;
ulli med, medd;

int main(){
	cin.tie(0);
	std::ios::sync_with_stdio(false);

	cin >> N;
	for(ulli i = 0; i < N; i++){
		cin >> X[i];
		Xs.push_back(X[i]);
	}
	sort(Xs.begin(), Xs.end());
	med = Xs[N/2];
	medd = Xs[(N/2)-1];

	for(ulli i = 0; i < N; i++){
		if(X[i] < med){
			cout << med << "\n";
		}else{
			cout << medd << "\n";
		}
	}

	return 0;
}
