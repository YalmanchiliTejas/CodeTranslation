#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<deque>
#include<queue>

using namespace std;

using lli = long long int;
using ulli = unsigned long long int;

//#define EVEL 1

#ifndef EVEL
#define dbug(X) std::cout << #X << ":" <<X<<" " ;
#define dbugf(s) std::cout << s << " ";
#define dbugln std::cout<<"\n";
#else
#define dbug(X) {}
#define dbugf(s) {}
#define dbugln {}
#endif

int a, b, c;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> a >> b >> c;
	if((b*10+c) % 4 == 0){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
  return 0;
}
