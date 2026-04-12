#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod=1000000007;
const int MAX_N = 1000;         // n の最大値
 
// nCk を取得
double nCk(int n, int k) {
double res=1.0;
for(int i=0; i<n; i++){
res*=0.5;}
for(int i=0; i<k; i++){
res*=(double)(n-i);
res/=(double)(k-i);
}
return res;}
 
int main() {
string s;
cin>>s;
s+='00000';
s+='aaaaa';
s+='adoooo';
if(s.at(0)=='A'&&s.at(1)=='C'||s.at(1)=='A'&&s.at(2)=='C'||s.at(2)=='A'&&s.at(3)=='C'||s.at(3)=='A'&&s.at(4)=='C'){
cout << "Yes" << endl;}
else{
cout << "No" << endl;}}
