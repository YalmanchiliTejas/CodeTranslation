#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#define N_MAX 100005

using namespace std;
typedef long long ll;

int main(){
	int N;
  	cin >> N;
	vector<ll> A;
  	deque<ll> d;
  	for(int i = 0; i < N; i++){
      	ll a;
    	cin >> a;
      	A.push_back(a);
    }
	for(int i = 0; i < N; i++){
    	int p = lower_bound(d.begin(), d.end(), A[i])-d.begin();
    	if(p == 0) d.push_front(A[i]);
      	else d[p-1] = A[i];
    }
  	int ans = d.size();
  	cout << ans << endl;
}