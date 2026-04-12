#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;
int N,H[100];
int main() {
cin >> N;
for (int i = 0; i < N; ++i){
    cin >> H[i];
}
int count=1;
std::vector<int> v = {};
for (int i = 1; i < N; ++i){
    std::vector<int> v = {};
    for(int j = 0; j < i; ++j){
        v.push_back(H[j]);
}
sort(v.begin(), v.end(), greater<int>());
if(H[i]>=v[0]) count ++;
}
cout << count << endl;
return 0;

}
