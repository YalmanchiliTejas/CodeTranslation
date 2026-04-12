#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

int N;
int a[maxn];

int main(){
	scanf("%d" , &N);
  	for(int i = 1; i <= N; ++i)scanf("%d" , &a[i]);
  	multiset<int> s;
  	int ans = 0;
  	for(int i = N; i >= 1; --i){
      auto it = s.upper_bound(a[i]);
      if(it == s.end()){
      	++ans;
        s.insert(a[i]);
      }
      else{
		s.erase(it);
        s.insert(a[i]);
      }
    }
  	printf("%d\n" , ans);
}