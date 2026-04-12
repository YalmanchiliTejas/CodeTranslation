#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int main() {
ll n;
cin>>n;
ll a[n]={};
ll b[n]={};
deque<ll> d;
ll aa;
for(ll i=0; i<n; i++){
cin>>a[i];}
ll counter=1000000;
for(ll i=0; i<n; i++){
if(i%2==0){
d.push_back(a[i]);}
else
d.push_front(a[i]);}
if(n%2==0){
while(!d.empty()){
aa=d.front();
d.pop_front();
cout<<aa<<" ";}}
else{
while(!d.empty()){
aa=d.back();
d.pop_back();
cout<<aa<<" ";}}}
