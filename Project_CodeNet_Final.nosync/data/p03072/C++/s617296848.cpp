#include<bits/stdc++.h>
#include<algorithm>
#include<iomanip>
#define mp make_pair
#define lli long long int
#define modi 1000000007
#define pb push_back
using namespace std;
int main(){
int n;
cin>>n;
int a[n];
int i;
for(i=0;i<n;i++){
    cin>>a[i];
}
int maxi=-1,count=0;
for(i=0;i<n;i++){
    if(a[i]>=maxi){
        maxi=a[i];
        count++;
    }
}
cout<<count<<endl;
}
