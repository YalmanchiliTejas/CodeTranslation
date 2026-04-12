#include <bits/stdc++.h>
using namespace std;

int main() {

//とりあえずAにすべての高さを入れる
  int N;
  cin >> N;
vector<int> vec(N);
for (int i = 0; i < N; i++) {
  cin >> vec.at(i);
}
//iより海に近い最大の高さの集合を作る
vector<int> v(N);
v.at(0) = vec.at(0);

for (int i =1; i<N;i++){
if (v.at(i-1)<vec.at(i))
  v.at(i) = vec.at(i);
else
v.at(i) = v.at(i-1);
}

//海を見れる旅館の数を求める
int a = 0;

for (int i = 0; i<N;i++){
if (vec.at(i)==v.at(i))
a++;
}
cout << a << endl;
}