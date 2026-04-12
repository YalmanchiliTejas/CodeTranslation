#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
int N; cin >> N;
 multiset<int> M;
  for(int i = 0; i < N; i++){
    int a; cin >> a;
    auto c = M.lower_bound(a);
    if( c != M.begin()){ c--;
      M.erase(c); } M.insert(a);
}

cout << (int)M.size() << endl; return 0;}