#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
int N, Ans = 1;cin >> N;
vector<int> H(N);

for(int i = 0; i < N; i++){
cin >> H.at(i);
}


for(int m = 1; m < N; m++){
int count = 0;

for(int i = 0; i < m; i++){
if(H.at(i) <= H.at(m))count++;
}

if(count == m)Ans++;

}
cout << Ans << endl;
}