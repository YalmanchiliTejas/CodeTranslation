#include <bits/stdc++.h>
using namespace std;
int main(){ 
int N; 
cin >> N; 
int A[30] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100}; 
for (int i = 0; i < N; ++i) {
string S; 
cin >> S; 
int B[30] = {0}; 
for(int j = 0; j < S.size(); ++j){
B[S.at(j) - 'a'] ++; 
}
for(int k=0; k < 26; k++){
A[k] = min(A[k], B[k]); 
}
}
for(char c = 'a'; c <= 'z'; ++c){
for(int j = 0; j < A[c - 'a'] ; ++j){
cout << c; 
}
}
cout << endl; 
}