#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
vector<int> v;
int flg;

for (int i=0; i<12; i++){
int t;
cin >> t;
v.push_back(t);
}
sort(v.begin(), v.end());
flg = true;
for (int i=0; i<3; i++){
for (int j=0; j<3; j++){
if (v[j*4+i]!=v[j*4+i+1]) flg = false;
}
}
cout << (flg?"yes":"no") << endl;
return 0;
} 
