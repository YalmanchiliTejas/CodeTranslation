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
int H, L;
cin>>H>>L;
string a[H]={};
int t[L]={};
int y[H]={};
int ca=0;
for(int i=0; i<H; i++){
cin>>a[i];}
for(int i=0; i<L; i++){
for(int q=0; q<H; q++){
if(a[q].at(i)=='#'){
t[i]++;
break;}}}
for(int i=0; i<H; i++){
for(int q=0; q<L; q++){
if(a[i].at(q)=='#'){
y[i]++;
break;}}}
for(int i=0; i<H; i++){
for(int q=0; q<L; q++){
if(t[q]==1&&y[i]==1){
cout<<a[i].at(q);
ca++;}}
if(ca>0){
cout<<endl;
ca=0;}}}
