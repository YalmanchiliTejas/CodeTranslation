#include <bits/stdc++.h>
using namespace std;

int main(){
int n;
int count = 0;
cin >> n;
vector<int> h(n);
for (int i = 0;i < n;i++){
  cin >> h.at(i);
}
int max = 0;
for(int i = 0;i < n;i++){
if (h.at(i) >= max){
  count += 1;
  max = h.at(i);
}
}
cout << count << endl;
}