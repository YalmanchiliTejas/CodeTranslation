#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<deque>
#include<queue>

using namespace std;

using lli = long long int;
using ulli = unsigned long long int;

#define EVEL 1

#ifndef EVEL
#define dbug(X) std::cout << #X << ":" <<X<<" " ;
#define dbugf(s) std::cout << s << " ";
#define dbugln std::cout<<"\n";
#else
#define dbug(X) {}
#define dbugf(s) {}
#define dbugln {}
#endif

int n;
ulli a, s;
ulli b[200010];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	if(n % 2 == 0){
		for(int i = 1; i <= n; i++){
			cin >> a;
			if(i%2 == 0){
				b[n/2-(i/2)] = a;
			}else{
				b[n/2+(i/2)]=a;
			}
		}
	}else{
		for(int i = 1; i <= n; i++){
			cin >> a;
			if(i%2 == 0){
				b[n/2+(i/2)] = a;
			}else{
				b[n/2-(i/2)] = a;
			}
		}
	}

	for(int i = 0; i < n-1; i++){
		cout << b[i] << " ";
	}
	cout << b[n-1] << endl;
  return 0;
}
