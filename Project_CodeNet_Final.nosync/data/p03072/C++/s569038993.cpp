 #include <bits/stdc++.h>
using namespace std;
 
int main() {
int N;
 cin >>N;
  
vector<int> A(N);
for (int i = 0; i < N; i++) {
cin >> A.at(i);
  }
int count=0;
for (int i = 0; i < N; i++) {
  bool flag=true;
for (int j = 0; j < i; j++) {
 
if(A[i]<A[j]){
  flag =false;
}
}
  if(flag){count++;}
}
cout <<count<<endl;
}